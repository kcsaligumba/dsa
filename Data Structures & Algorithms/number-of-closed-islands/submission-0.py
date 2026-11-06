from collections import deque

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        neighbors = [(0, -1), (-1, 0), (0, 1), (1, 0)]
        count = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] != 0:
                    continue
                
                queue = deque([(i, j)])
                grid[i][j] = '#'
                isClosed = True

                while queue:
                    r, c = queue.popleft()
                    if (r == 0 or r == n - 1 or
                        c == 0 or c == m - 1):
                        isClosed = False
                    
                    for dr, dc in neighbors:
                        nr, nc = r + dr, c + dc
                        if (nr not in range(n) or
                            nc not in range(m) or
                            grid[nr][nc] != 0):
                            continue
                        
                        grid[nr][nc] = '#'
                        queue.append((nr, nc))

                if isClosed:
                    count += 1
        
        return count
