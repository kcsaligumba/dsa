class Solution:
    def countSubstrings(self, s: str) -> int:
        palindromes = 0
        n = len(s)
        for i in range(n):
            # odd
            left, right = i, i
            while left in range(n) and right in range(n) and s[left] == s[right]:
                palindromes += 1
                left -= 1
                right += 1
            
            # even
            left, right = i - 1, i
            while left in range(n) and right in range(n) and s[left] == s[right]:
                palindromes += 1
                left -= 1
                right += 1
        return palindromes