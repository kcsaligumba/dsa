class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0

        windowFreq = {}
        l = 0
        for r in range(len(s)):
            right = s[r]
            windowFreq[right] = windowFreq.get(right, 0) + 1
            while windowFreq[right] > 1:
                left = s[l]
                windowFreq[left] -= 1
                l += 1
            res = max(res, r - l + 1)
        
        return res