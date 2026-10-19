class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        parent = [i for i in range(rows * cols)]
        neighbors = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        maxArea = 1 if 1 in [grid[r][c] for r in range(rows) for c in range(cols)] else 0

        def findParent(r, c):
            idx = r * cols + c
            while idx != parent[idx]:
                parent[idx] = parent[parent[idx]]
                idx = parent[idx]
            return idx

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    continue
                
                for dr, dc in neighbors:
                    nr, nc = r + dr, c + dc

                    if (nr not in range(rows) or 
                        nc not in range(cols) or 
                        grid[nr][nc] == 0):
                        continue
                    
                    p, np = findParent(r, c), findParent(nr, nc)
                    pr, pc = p // cols, p % cols
                    npr, npc = np // cols, np % cols

                    if p == np:
                        continue
                    if grid[pr][pc] >= grid[npr][npc]:
                        parent[np] = p
                        grid[pr][pc] += grid[npr][npc]
                        maxArea = max(maxArea, grid[pr][pc])
                    else:
                        parent[p] = np
                        grid[npr][npc] += grid[pr][pc]
                        maxArea = max(maxArea, grid[npr][npc])
        
        return maxArea

"""
0   3   1
0   1   0
1   0   0
Output: 3
parent = [0, 1, 1, 3, 1, 5, 6, 7, 8]
maxArea = 3
"""