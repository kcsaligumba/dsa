class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = [i for i in range(n + 1)]
        rank = [1] * (n + 1)

        def findParent(node):
            while node != parent[node]:
                parent[node] = parent[parent[node]]
                node = parent[node]
            return node

        for u, v in edges:
            upar, vpar = findParent(u), findParent(v)
            if upar == vpar:
                return [u, v]
            elif rank[upar] >= rank[vpar]:
                rank[upar] += rank[vpar]
                parent[vpar] = upar
            else:
                rank[vpar] += rank[upar]
                parent[upar] = vpar