class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board), len(board[0])
        neighbors = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        notCaptured = set(
            {
                (r, c)
                for r in range(m)
                for c in range(n)
                if (board[r][c] == 'O' and 
                (r == 0 or c == 0 or r == m - 1 or c == n - 1))
            }
        )
        queue = deque(
            [
                (r, c)
                for r in range(m)
                for c in range(n)
                if (board[r][c] == 'O' and 
                (r == 0 or c == 0 or r == m - 1 or c == n - 1))
            ]
        )
        while queue:
            r, c = queue.popleft()
            
            for dr, dc in neighbors:
                nr, nc = r + dr, c + dc
                if (nr not in range(m) or
                    nc not in range(n) or
                    (nr, nc) in notCaptured or
                    board[nr][nc] == 'X'):
                    continue
                
                queue.append((nr, nc))
                notCaptured.add((nr, nc))
        
        for r in range(m):
            for c in range(n):
                if board[r][c] == 'X' or (r, c) in notCaptured:
                    continue
                board[r][c] = 'X'