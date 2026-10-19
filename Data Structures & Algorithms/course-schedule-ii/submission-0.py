class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses
        for c, p in prerequisites:
            adj[p].append(c)
            indeg[c] += 1
        
        queue = deque([c for c in range(numCourses) if indeg[c] == 0])
        finished = 0
        path = []
        while queue:
            cur = queue.popleft()
            finished += 1
            path.append(cur)

            for nei in adj[cur]:
                indeg[nei] -= 1
                if indeg[nei] == 0:
                    queue.append(nei)
        
        if finished != numCourses:
            return []
        
        return path