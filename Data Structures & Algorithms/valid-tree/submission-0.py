class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        queue = deque([(0, -1)])
        visited = set({0})
        while queue:
            cur, par = queue.popleft()

            for nei in adj[cur]:
                if nei == par:
                    continue
                if nei in visited:
                    return False
                queue.append((nei, cur))
                visited.add(nei)

        return len(visited) == n