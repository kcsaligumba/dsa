class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        
        money = { -2 : 0, -1 : 0 }
        for i in range(n):
            money[i] = max(money[i - 1], nums[i] + money[i - 2])
        return money[n - 1]