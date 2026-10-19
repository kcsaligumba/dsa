class Solution:
    def canJump(self, nums: List[int]) -> bool:
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i - 1] - 1)
        
        return 0 not in nums[:len(nums) - 1]