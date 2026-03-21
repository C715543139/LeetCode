class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        sums = set()
        for i in range(len(nums)):
            target = -nums[i]
            numsForCandidate = set()
            for j in range(i + 1, len(nums)):
                if nums[j] not in numsForCandidate:
                    numsForCandidate.add(target - nums[j])
                else:
                    sums.add((nums[i], target - nums[j], nums[j]))
        result = [list(sum) for sum in sums]
        return result


nums = [-1, 0, 1, 2, -1, -4]
print(Solution().threeSum(nums))
