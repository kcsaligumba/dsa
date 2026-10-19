class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses
        for c, p in prerequisites:
            adj[p].append(c) # course -> prerequisite
            indeg[c] += 1 # course -> number of prerequisites
        
        queue = deque([c for c in range(numCourses) if indeg[c] == 0])
        finished = 0
        while queue:
            cur = queue.popleft()
            finished += 1

            for nei in adj[cur]:
                indeg[nei] -= 1
                if indeg[nei] == 0:
                    queue.append(nei)
        
        return finished == numCourses