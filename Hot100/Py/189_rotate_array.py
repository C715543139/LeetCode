from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        k %= length
        res = []
        for i in range(-k, length - k):
            res.append(nums[i])
        for i in range(length):
            nums[i] = res[i]


class Solution2:
    def rotate(self, nums: List[int], k: int) -> None:
        length = len(nums)
        k %= length
        l = nums[:length - k]
        r = nums[length - k:]
        for i in range(k):
            nums[i] = r[i]
        for i in range(length - k):
            nums[i + k] = l[i]


class Solution3:
    def rotate(self, nums: List[int], k: int) -> None:
        length = len(nums)
        k %= length
        if length == 1 or k == 0:
            return

        def swap(i, j, p, q):
            if p == q:
                for idx in range(j - i + 1):
                    nums[j - idx], nums[p - idx] = nums[p - idx], nums[j - idx]
                return
            swap(i, j, p, p)
            swap(i + 1, j + 1, p + 1, q)

        swap(0, length - k - 1, length - k, length - 1)


class Solution4:
    def rotate(self, nums: List[int], k: int) -> None:
        length = len(nums)
        k %= length

        for i in range(length - k, length):
            for j in range(length - k):
                nums[i - j], nums[i - j - 1] = nums[i - j - 1], nums[i - j]

class Solution5:
    def rotate(self, nums: List[int], k: int) -> None:
        length = len(nums)
        k %= length
        if length == 1 or k == 0:
            return

        for i in range(length // 2):
            nums[i], nums[-(i + 1)] = nums[-(i + 1)], nums[i]
        for i in range(k // 2):
            nums[i], nums[k - i - 1] = nums[k - i - 1], nums[i]
        for i in range((length - k) // 2):
            nums[i + k], nums[-(i + 1)] = nums[-(i + 1)], nums[i + k]


nums = [-1,-100,3,99]
k = 3
Solution5().rotate(nums, k)
print(nums)
