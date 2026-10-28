class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result, pair = [], []
        def dfs(o, c):
            if o == c == n:
                result.append("".join(pair))
                return
            
            if o < n:
                pair.append("(")
                dfs(o + 1, c)
                pair.pop()
            if c < o:
                pair.append(")")
                dfs(o, c + 1)
                pair.pop()
        dfs(0, 0)
        return result