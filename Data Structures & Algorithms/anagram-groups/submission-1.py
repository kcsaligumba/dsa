class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        toReturn = []
        anagrams = {}
        for s in strs:
            sorted_s = "".join(sorted(s))
            if (sorted_s not in anagrams):
                anagrams[sorted_s] = [s]
            else:
                anagrams[sorted_s].append(s)
        for val in anagrams.values():
            toReturn.append(val)
        return toReturn
            

