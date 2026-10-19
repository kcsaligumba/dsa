class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sortedToStrs = defaultdict(list)
        for s in strs:
            sortedStr = "".join(sorted(s))
            sortedToStrs[sortedStr].append(s)
        
        return list(sortedToStrs.values())
