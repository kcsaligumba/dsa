class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2**31 - 1
        m, n = len(grid), len(grid[0])
        queue = deque(
            [(i, j, 0) 
            for i in range(m) 
            for j in range(n) 
            if grid[i][j] == 0]
        )
        neighbors = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        
        while queue:
            r, c, d = queue.popleft()

            for dr, dc in neighbors:
                nr, nc = r + dr, c + dc
                if (nr not in range(m) or
                    nc not in range(n) or
                    grid[nr][nc] < INF):
                    continue
                
                queue.append((nr, nc, d + 1))
                grid[nr][nc] = d + 1
