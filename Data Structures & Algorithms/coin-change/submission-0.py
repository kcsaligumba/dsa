class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        minCoins = [amount + 1] * (amount + 1)
        minCoins[0] = 0

        for i in range(1, amount + 1):
            for c in coins:
                if i >= c:
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - c])
        
        return minCoins[amount] if minCoins[amount] != amount + 1 else -1