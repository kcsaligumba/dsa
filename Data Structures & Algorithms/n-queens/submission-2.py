class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result, board = [], []
        cols, diag, anti = set(), set(), set()
        
        def dfs(r):
            if r == n:
                result.append(board.copy())
                return
            
            for c in range(n):
                if c in cols or (r - c) in diag or (r + c) in anti:
                    continue
                
                cols.add(c)
                diag.add(r - c)
                anti.add(r + c)
                board.append('.' * c + 'Q' + '.' * (n - c - 1))

                dfs(r + 1)

                board.pop()
                cols.remove(c)
                diag.remove(r - c)
                anti.remove(r + c)
        
        dfs(0)
        return result