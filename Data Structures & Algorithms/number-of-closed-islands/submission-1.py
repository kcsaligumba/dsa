from collections import deque

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        neighbors = [(0, -1), (-1, 0), (0, 1), (1, 0)]
        count = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    continue
                
                queue = deque([(i, j)])
                grid[i][j] = 1
                isClosed = True

                while queue:
                    r, c = queue.popleft()
                    if (r in (0, n - 1) or c in (0, m - 1)):
                        isClosed = False
                    
                    for dr, dc in neighbors:
                        nr, nc = r + dr, c + dc
                        if (nr not in range(n) or
                            nc not in range(m) or
                            grid[nr][nc]):
                            continue
                        
                        grid[nr][nc] = 1
                        queue.append((nr, nc))

                if isClosed:
                    count += 1
        
        return count
