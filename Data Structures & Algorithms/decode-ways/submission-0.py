class Solution:
    def numDecodings(self, s: str) -> int:
        cache = {len(s): 1}

        def decode(i):
            if i in cache:
                return cache[i]
            
            if s[i] == "0":
                return 0
            
            result = decode(i + 1)
            if (i + 1 < len(s) and
                int(s[i : i + 2]) >= 10 and
                int(s[i : i + 2]) <= 26):
                result += decode(i + 2)
            
            cache[i] = result
            return result
        
        return decode(0)