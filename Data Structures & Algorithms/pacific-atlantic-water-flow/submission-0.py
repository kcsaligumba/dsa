class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        neighbors = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        result = []

        pacific = set()
        pacific.update([(i, 0) for i in range(m)], [(0, j) for j in range(1, n)])
        stack = list(pacific)

        while stack:
            r, c = stack.pop()

            for dr, dc in neighbors:
                nr, nc = r + dr, c + dc
                if (nr not in range(m) or
                    nc not in range(n) or
                    (nr, nc) in pacific or
                    heights[nr][nc] < heights[r][c]):
                    continue
                
                stack.append((nr, nc))
                pacific.add((nr, nc))

        atlantic = set()
        atlantic.update([(i, n - 1) for i in range(m)], [(m - 1, j) for j in range(n - 1)])
        stack = list(atlantic)

        while stack:
            r, c = stack.pop()

            for dr, dc in neighbors:
                nr, nc = r + dr, c + dc
                if (nr not in range(m) or
                    nc not in range(n) or
                    (nr, nc) in atlantic or
                    heights[nr][nc] < heights[r][c]):
                    continue
                
                stack.append((nr, nc))
                atlantic.add((nr, nc))
        
        for r, c in pacific:
            if (r, c) in atlantic:
                result.append([r, c])
        
        return result