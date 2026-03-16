from ast import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsForCandidate = dict()
        for i, num in enumerate(nums):
            numToFind = target - num
            if numToFind in numsForCandidate:
                return [numsForCandidate[numToFind], i]
            numsForCandidate[num] = i
        return None
