import heapq
from collections import Counter, deque
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap = [(-num, i) for i, num in enumerate(nums[:k])]
        heapq.heapify(heap)
        result = [-heap[0][0]]
        for i in range(1, len(nums) - k + 1):
            heapq.heappush(heap, (-nums[i + k - 1], i + k - 1))
            while heap[0][1] < i:
                heapq.heappop(heap)
            result.append(-heap[0][0])
        return result


class Solution2:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        dq = deque()
        for i in range(k):
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()
            dq.append(i)
        result.append(nums[dq[0]])
        for i in range(k, len(nums)):
            # 比新加进来的还小的永远不会成为最大值
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()
            dq.append(i)
            # 最大值需要在窗口范围内
            while dq[0] < i - k + 1:
                dq.popleft()
            result.append(nums[dq[0]])
        return result


nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
print(Solution().maxSlidingWindow(nums, k))
