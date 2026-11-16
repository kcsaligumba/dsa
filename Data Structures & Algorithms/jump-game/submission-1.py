class Solution:
    def canJump(self, nums: List[int]) -> bool:
        prefix = [nums[0]]
        for i in range(1, len(nums)):
            prefix.append(max(nums[i], prefix[i - 1] - 1))
        return 0 not in prefix[:-1]