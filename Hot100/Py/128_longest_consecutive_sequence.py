from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # 去重 + 排序
        uniqueBucket = sorted(set(nums))

        if not uniqueBucket:
            return 0

        longest = 0
        count = 1
        lastNum = uniqueBucket[0]
        for num in uniqueBucket[1:]:
            if num == lastNum + 1:
                count += 1
            else:
                longest = max(longest, count)
                count = 1
            lastNum = num
        longest = max(longest, count)
        return longest


class Solution2:
    # 桶排序
    class Bitmap:
        def __init__(self, minNum: int, maxNum: int, bitWidth: int) -> None:
            self.min = minNum
            self.max = maxNum
            self.bitWidth: int = bitWidth
            numWidth = maxNum - minNum + 1
            self.bitmap: list[int] = [0] * (numWidth // self.bitWidth + 1)

        def flagOn(self, num: int) -> None:
            num = num - self.min
            idx = num // self.bitWidth
            self.bitmap[idx] |= (1 << (num - idx * self.bitWidth))

        def flagOff(self, num: int) -> None:
            num = num - self.min
            idx = num // self.bitWidth
            self.bitmap[idx] &= (0 << (num - idx * self.bitWidth))

        def toList(self) -> list[int]:
            output: list[int] = []
            for idx, bit in enumerate(self.bitmap):
                if bit != 0:
                    for i in range(self.bitWidth):
                        if bit & (1 << i) != 0:
                            output.append(idx * self.bitWidth + i + self.min)
            return output

        def fromList(self, nums: list[int]):
            for num in nums:
                self.flagOn(num)
            return self

    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        uniqueBucket = self.Bitmap(min(nums), max(nums), 4096).fromList(nums).toList()

        longest = 0
        count = 1
        lastNum = uniqueBucket[0]
        for num in uniqueBucket[1:]:
            if num == lastNum + 1:
                count += 1
            else:
                longest = max(longest, count)
                count = 1
            lastNum = num
        longest = max(longest, count)
        return longest


class Solution3:
    def longestConsecutive(self, nums: List[int]) -> int:
        uniqueBucket = set(nums)
        longest = 0
        for num in uniqueBucket:
            count = 1
            if num - 1 not in uniqueBucket:
                nextNum = num + 1
                while nextNum in uniqueBucket:
                    count += 1
                    nextNum += 1
                longest = max(longest, count)
        return longest


nums = [1]
print(Solution3().longestConsecutive(nums))
