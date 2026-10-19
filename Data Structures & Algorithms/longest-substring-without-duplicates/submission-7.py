class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        curWindow = set()
        maxWindow = 0
        for r in range(len(s)):
            while s[r] in curWindow:
                curWindow.remove(s[l])
                l += 1
            curWindow.add(s[r])
            maxWindow = max(maxWindow, r - l + 1)
        return maxWindow