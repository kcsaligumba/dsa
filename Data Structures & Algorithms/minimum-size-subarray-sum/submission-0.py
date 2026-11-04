class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        best_size = float('inf')
        cur_sum = 0
        l = 0
        for r in range(len(nums)):
            cur_sum += nums[r]
            while cur_sum >= target:
                best_size = min(best_size, r - l + 1)
                cur_sum -= nums[l]
                l += 1
        return best_size if best_size < float('inf') else 0