from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        result = 0
        for i in range(len(nums)):
            sum = 0
            for j in range(i, len(nums)):
                sum += nums[j]
                if sum == k:
                    result += 1
        return result


class Solution2:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if len(nums) < 2:
            return 1 if nums[0] == k else 0

        # 转化为前缀和 sum(nums[0:i]) = nums[i]
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        # sum(nums[i:j]) = nums[j] - nums[i - 1] = k
        # nums[j] = k + nums[i - 1]
        # 两数之和
        count = 0
        hashMap = dict()
        hashMap[k] = 1
        for i in range(len(nums)):
            if nums[i] in hashMap:
                count += hashMap[nums[i]]
            hashMap[nums[i] + k] = hashMap.get(nums[i] + k, 0) + 1
        return count


nums = [1, 2, 3]
k = 3
print(Solution2().subarraySum(nums, k))
