class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        oranges, mins = 0, 0
        r, c = len(grid), len(grid[0])
        
        q = deque()
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    oranges += 1
                
        while q:
            n = len(q)
            for i in range(n):
                i, j = q.popleft()
                if i - 1 in range(r) and grid[i - 1][j] == 1:
                    oranges -= 1
                    grid[i - 1][j] = 2
                    q.append((i - 1, j))
                if i + 1 in range(r) and grid[i + 1][j] == 1:
                    oranges -= 1
                    grid[i + 1][j] = 2
                    q.append((i + 1, j))
                if j - 1 in range(c) and grid[i][j - 1] == 1:
                    oranges -= 1
                    grid[i][j - 1] = 2
                    q.append((i, j - 1))
                if j + 1 in range(c) and grid[i][j + 1] == 1:
                    oranges -= 1
                    grid[i][j + 1] = 2
                    q.append((i, j + 1))
            if len(q) > 0:
                mins += 1
        
        return mins if oranges == 0 else -1