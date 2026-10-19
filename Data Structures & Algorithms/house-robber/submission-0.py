class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        
        maxCash = [0] * (n + 1)
        maxCash[1] = nums[0]

        for i in range(1, n):
            index = i + 1
            maxCash[index] = max(nums[i] + maxCash[index - 2], maxCash[index - 1])
        
        return max(maxCash[n], maxCash[n - 1])