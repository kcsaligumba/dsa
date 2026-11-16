class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = nums[0]
        left, cur = 0, 0
        for right in range(len(nums)):
            cur += nums[right]
            best = max(best, cur)
            if cur < 0:
                left = right + 1
                cur = 0
        return best