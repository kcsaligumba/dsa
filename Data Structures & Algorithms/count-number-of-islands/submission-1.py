class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        parent = [i for i in range(rows * cols)]
        rank = [1] * (rows * cols)

        count = sum(int(grid[r][c]) for r in range(rows) for c in range(cols))
        neighbors = [(0, -1), (0, 1), (1, 0), (-1, 0)] # L, R, U, D

        def findParent(r, c):
            idx = r * cols + c
            while idx != parent[idx]:
                parent[idx] = parent[parent[idx]]
                idx = parent[idx]
            return idx

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "0":
                    continue
                
                for dr, dc in neighbors:
                    nr, nc = r + dr, c + dc

                    if nr not in range(rows) or nc not in range(cols):
                        continue
                    if grid[nr][nc] == "0":
                        continue
                    
                    p, op = findParent(r, c), findParent(nr, nc)
                    
                    if p == op:
                        continue
                    if rank[p] >= rank[op]:
                        parent[op] = p
                        rank[p] += rank[op]
                    else:
                        parent[p] = op
                        rank[op] += rank[p]
                    count -= 1
        
        return count

"""
0   1   1
0   1   0
1   0   0
Output = 2
parent = [0, 1, 1, 3, 1, 5, 6, 7, 8]
rank =   [1, 3, 1, 1, 1, 1, 1, 1, 1]
count = 4 - 1 - 1 = 2

"""