class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        rank = [1] * n
        count = n

        def findParent(i):
            while i != parent[i]:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i

        for a, b in edges:
            pa, pb = findParent(a), findParent(b)
            if pa == pb:
                continue
            if rank[pa] >= rank[pb]:
                parent[pa] = pb
                rank[pa] += rank[pb]
            else:
                parent[pb] = pa
                rank[pb] += rank[pa]
            count -= 1
        
        return count