from typing import Dict, List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupMap: Dict[str, List[str]] = dict()
        for word in strs:
            wordSorted = "".join(sorted(word))
            if wordSorted not in groupMap:
                groupMap[wordSorted] = [word]
            else:
                groupMap[wordSorted].append(word)

        return list(groupMap.values())

class Solution2:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupMap: Dict[tuple[int, ...], List[str]] = dict()
        for word in strs:
            bucket: list[int] = [0] * 26
            for char in word:
                bucket[ord(char) - ord("a")] += 1
            bucketTuple: tuple[int, ...] = tuple(bucket)
            if bucketTuple not in groupMap:
                groupMap[bucketTuple] = [word]
            else:
                groupMap[bucketTuple].append(word)
        return list(groupMap.values())
