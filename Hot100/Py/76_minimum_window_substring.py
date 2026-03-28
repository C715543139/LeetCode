from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tDict = dict()
        tLen = len(t)
        for c in t:
            tDict[c] = tDict.get(c, 0) + 1

        res = ''
        minLen = len(s) + 1
        for i in range(len(s) - tLen + 1):
            if s[i] not in tDict:
                continue

            remainDict = tDict.copy()
            remainCount = tLen
            for j in range(i, len(s)):
                c = s[j]
                if c not in tDict:
                    continue
                else:
                    if remainDict[c] > 0:
                        remainDict[c] -= 1
                        remainCount -= 1

                    if remainCount == 0 and j - i + 1 < minLen:
                        res = s[i:j + 1]
                        minLen = j - i + 1
                        break
        return res


class Solution2:
    def minWindow(self, s: str, t: str) -> str:
        bucket = [0] * 58
        count = 0
        for c in t:
            bucket[ord(c) - ord('A')] += 1
            count += 1

        res = ''
        minLen = len(s) + 1
        p, q = 0, 0  # 头尾（包含）
        while q < len(s):
            while True:
                # 右指针移动到t中字符
                while q < len(s) and s[q] not in t:
                    q += 1
                # 到达终止条件
                if q == len(s):
                    return res
                # 将s[q]放入并判断
                bucket[ord(s[q]) - ord('A')] -= 1
                # 有效的增加
                if bucket[ord(s[q]) - ord('A')] >= 0:
                    count -= 1
                # 找到符合要求的q
                if count == 0:
                    break
                else:
                    q += 1

            while True:
                # 此时右端已经满足，收缩左端
                # 左指针移动到t中字符
                while s[p] not in t:
                    p += 1
                assert p <= q
                assert q < len(s)
                # 如果收缩后仍满足，则收缩，否则退出
                if p < q and bucket[ord(s[p]) - ord('A')] <= -1:
                    bucket[ord(s[p]) - ord('A')] += 1
                    p += 1
                else:
                    break

            if q - p + 1 < minLen:
                res = s[p:q + 1]
                minLen = q - p + 1

            assert s[p] in t
            # 窗口向右移动
            bucket[ord(s[p]) - ord('A')] += 1
            count += 1
            p += 1
            q += 1

        return res


class Solution3:
    def minWindow(self, s: str, t: str) -> str:
        bucket = defaultdict(int)
        diff = 0
        for c in t:
            bucket[c] += 1
            diff += 1

        p = 0
        res = ''
        resLen = len(s) + 1
        for q, c in enumerate(s):
            if c not in bucket:
                continue

            bucket[c] -= 1
            if bucket[c] >= 0:
                diff -= 1

            if diff != 0:
                continue

            # 跳过无关字符和多余字符
            while s[p] not in bucket or bucket[s[p]] <= -1:
                if s[p] in bucket:          # 只有“多余字符”才需要回补
                    bucket[s[p]] += 1
                p += 1

            if q - p + 1 < resLen:
                res = s[p:q + 1]
                resLen = q - p + 1

        return res


s = "A"
t = "A"
print(Solution3().minWindow(s, t))
