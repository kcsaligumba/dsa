class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res, pal = [], []
        def isPalindrome(st):
            l, r = 0, len(st) - 1
            while l < r:
                if st[l] != st[r]:
                    return False
                l += 1
                r -= 1
            return True
        def dfs(i):
            if i == len(s):
                res.append(pal.copy())
                return
            
            for j in range(i, len(s)):
                if isPalindrome(s[i : j + 1]):
                    pal.append(s[i : j + 1])
                    dfs(j + 1)
                    pal.pop()
        dfs(0)
        return res