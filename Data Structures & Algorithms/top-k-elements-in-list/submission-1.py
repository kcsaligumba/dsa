class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        toReturn = []
        for n in nums:
            if n not in freq:
                freq[n] = 1
            else:
                freq[n] += 1
        freq = sorted(freq, key = freq.get)
        for i in range(k):
            toReturn.append(freq[len(freq) - 1 - i])
        return toReturn