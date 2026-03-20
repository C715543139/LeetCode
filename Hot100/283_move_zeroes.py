from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numsCopy = nums.copy()
        p = 0
        for i in range(len(nums)):
            while  p < len(numsCopy) and numsCopy[p] == 0:
                p += 1
            if p == len(numsCopy):
                nums[i] = 0
            else:
                nums[i] = numsCopy[p]
                p += 1


class Solution2:
    def moveZeroes(self, nums: List[int]) -> None:
        for i in range(len(nums)):
            if nums[i] == 0:
                p = i # 0的位置
                q = i + 1 # 非0的位置
                while q < len(nums):
                    if nums[q] != 0:
                        nums[p], nums[q] = nums[q], nums[p]
                        p = q
                        q += 1
                    else:
                        q += 1

class Solution3:
    def moveZeroes(self, nums: List[int]) -> None:
        p = 0
        q = 0
        while p < len(nums):
            # 找到非0位置
            while q < len(nums) and nums[q] == 0:
                q += 1
            if q == len(nums):
                break
            else:
                nums[p], nums[q] = nums[q], nums[p]
                p += 1
                q += 1

nums = [0,1,0,0,0,0,1,0,3,12]
Solution3().moveZeroes(nums)
print(nums)