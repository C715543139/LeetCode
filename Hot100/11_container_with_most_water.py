from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Column = min(h1, h2) * width
        # width减小时, min(h1, h2)增加才有可能增大
        p, q = 0, len(height) - 1
        maxColumn = 0
        while p < q:
            maxColumn = max(maxColumn, min(height[p], height[q]) * (q - p))
            if height[p] < height[q]:
                p += 1
            else:
                q -= 1
        return maxColumn


height = [1,8,6,2,5,4,8,3,7]
print(Solution().maxArea(height))