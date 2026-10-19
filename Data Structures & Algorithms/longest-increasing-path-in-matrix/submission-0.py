class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        lip = [[0 for _ in range(n)] for _ in range(m)]
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        def dfs(r, c, prevVal):
            nonlocal lip
            if (r not in range(m) or 
                c not in range(n) or
                matrix[r][c] <= prevVal):
                return 0
            if lip[r][c] > 0:
                return lip[r][c]
            res = 1
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                res = max(res, 1 + dfs(nr, nc, matrix[r][c]))
            lip[r][c] = res
            return res
                    
        res = 1
        for r in range(m):
            for c in range(n):
                res = max(res, dfs(r, c, -1))
        
        return res