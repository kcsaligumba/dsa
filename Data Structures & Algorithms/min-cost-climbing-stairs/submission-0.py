class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        minCost = [0] * (n + 2)
        minCost[:n] = cost[:n]
        for i in range(2, n + 2):
            minCost[i] += min(minCost[i - 1], minCost[i - 2])
        return min(minCost[n - 1], minCost[n])