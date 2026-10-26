class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
            
        first, second = 1, 1
        for i in range(1, len(s)):
            count = 0
            if s[i] != "0":
                count += first
            if 10 <= int(s[i - 1 : i + 1]) <= 26:
                count += second
            first, second = count, first
        return first