class Solution:
    def climbStairs(self, n: int) -> int:
        ways = { -1 : 1, 0 : 1 }
        for i in range(1, n):
            ways[i] = ways[i - 1] + ways[i - 2]
        return ways[n - 1]