class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        toReturn = []
        anagrams = {}
        for i, s in enumerate(strs):
            sorted_s = "".join(sorted(s))
            if (sorted_s not in anagrams):
                anagrams[sorted_s] = [strs[i]]
            else:
                anagrams[sorted_s].append(strs[i])
        for val in anagrams.values():
            toReturn.append(val)
        return toReturn
            

