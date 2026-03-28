from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        nums.insert(0, 0)
        minSum = nums[0]
        maxSub = nums[1]
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
            maxSub = max(maxSub, nums[i] - minSum)
            minSum = min(minSum, nums[i])

        return maxSub


nums = [5, 4, -1, 7, 8]
print(Solution().maxSubArray(nums))
