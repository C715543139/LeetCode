class Solution:
    # 移动右指针
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        if len(s) == 1:
            return 1

        p = 1
        substr = s[0]
        longest = 1
        while p < len(s):
            idx = substr.find(s[p])
            if idx != -1:
                longest = max(longest, len(substr))
                substr = substr[idx + 1:]
            else:
                substr += s[p]
                p += 1
                longest = max(longest, len(substr))
        return longest


class Solution2:
    # 移动左指针
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        if len(s) == 1:
            return 1

        p, q = 0, 1
        substr = set(s[p])
        longest = 1
        while p < len(s):
            while q < len(s) and s[q] not in substr:
                substr.add(s[q])
                q += 1
            longest = max(longest, len(substr))
            substr.remove(s[p])
            p += 1
        return longest


class Solution3:
    def lengthOfLongestSubstring(self, s: str) -> int:
        record = dict()
        longest = 0
        start = -1
        for i, c in enumerate(s):
            if c in record:
                start = max(start, record[c])
            record[c] = i
            longest = max(longest, i - start)
        return longest


s = "dvdf"
print(Solution3().lengthOfLongestSubstring(s))
