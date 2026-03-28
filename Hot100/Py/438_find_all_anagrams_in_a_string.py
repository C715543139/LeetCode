from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p = sorted(p)
        lenP = len(p)
        index = []
        for i in range(len(s) - lenP + 1):
            if sorted(s[i:i + lenP]) == p:
                index.append(i)
        return index


class Solution2:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        lenP = len(p)
        need, excess = [], []
        index = []
        for i in range(len(s) - lenP + 1):
            if i == 0:
                tempP = list(p)
                for char in s[:lenP]:
                    if char in tempP:
                        tempP.remove(char)
                    else:
                        excess.append(char)
                need.extend(tempP)
            else:
                if s[i - 1] != s[i + lenP - 1]:
                    # 减去的若非多余，则为需要
                    if s[i - 1] in excess:
                        excess.remove(s[i - 1])
                    else:
                        need.append(s[i - 1])

                    # 加上的若非需要，则为多余
                    if s[i + lenP - 1] in need:
                        need.remove(s[i + lenP - 1])
                    else:
                        excess.append(s[i + lenP - 1])

            if need == [] and excess == []:
                index.append(i)
        return index


s = "abab"
p = "ab"
print(Solution2().findAnagrams(s, p))
