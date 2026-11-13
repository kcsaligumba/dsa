class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = defaultdict(list)
        for dep, arr in sorted(tickets, reverse=True):
            adj[dep].append(arr)

        route = []

        def dfs(airport):
            while adj[airport]:
                dfs(adj[airport].pop())
            route.append(airport)

        dfs("JFK")
        return route[::-1]