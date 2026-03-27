from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def mergeTwoList(list1, list2) -> list[int] | None:
            x1, y1 = list1
            x2, y2 = list2
            # x2, y2代表更长段
            if y1 - x1 > y2 - x2:
                m1, n1 = x1, y1
                x1, y1 = x2, y2
                x2, y2 = m1, n1
            assert y2 - x2 >= y1 - x1
            # x1 ---- y1
            #    x2 ------------ y2
            if x1 < x2 <= y1:
                return [x1, y2]
            #    x1 ---- y1
            # x2 ------------ y2
            elif x1 >= x2 and y1 <= y2:
                return [x2, y2]
            #             x1 ---- y1
            # x2 ------------- y2
            elif x1 <= y2 < y1:
                return [x2, y1]
            else:
                return None

        flag = False
        while not flag:
            flag = True
            for i in range(len(intervals)):
                for j in range(i + 1, len(intervals)):
                    list1, list2 = intervals[i], intervals[j]
                    merged = mergeTwoList(list1, list2)
                    if merged is not None:
                        intervals.remove(list1)
                        intervals.remove(list2)
                        intervals.append(merged)
                        flag = False
                        break
                if not flag:
                    break

        return intervals


class Solution2:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        start, end = 0, 0
        for p, q in intervals:
            start = min(start, p)
            end = max(end, q)
        len = end - start + 1
        # 0空, 1(01)与右侧相连, 2(10)与左侧相连, 3(11)与左右相连, 4(100)只含自身
        bucket = [0] * len
        for p, q in intervals:
            for i in range(p + 1, q):
                bucket[i - len] = 3
            if p == q:
                bucket[p - len] |= 4
            else:
                bucket[p - len] |= 1
                bucket[q - len] |= 2
        temp = []
        res = []
        counting = False
        for i in range(start, end + 1):
            if not counting:
                if bucket[i - len] & 1 == 1:
                    temp.append(i)
                    counting = True
                elif bucket[i - len] & 4 == 4:
                    res.append([i, i])
            else:
                if bucket[i - len] & 2 == 2 and bucket[i - len] & 1 == 0:
                    temp.append(i)
                    counting = False
                    res.append(temp)
                    temp = []
        return res


class Solution3:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = [intervals[0]]
        for p, q in intervals[1:]:
            last = res[-1]
            if p > last[1]:
                res.append([p, q])
            elif q > last[1]:
                res[-1][1] = q
        return res


intervals = [[1, 4], [0, 0]]
print(Solution3().merge(intervals))
