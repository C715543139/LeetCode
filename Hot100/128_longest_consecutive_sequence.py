from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
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


nums = [100, 4, 200, 1, 3, 2]
print(Solution().longestConsecutive(nums))
