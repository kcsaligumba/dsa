class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = [set() for _ in range(n + 1)] # node -> list of (weight, next_node)

        for u, v, w in times:
            adj[u].add((v, w))

        heap = [(0, k)] # heap of (total_time, node)
        seen = set()
        res = 0

        while heap:
            time, u = heapq.heappop(heap)

            if u in seen:
                continue
            seen.add(u)

            res = time

            for v, w in adj[u]:
                if v not in seen:
                    heapq.heappush(heap, (time + w, v))
        
        return res if len(seen) == n else -1