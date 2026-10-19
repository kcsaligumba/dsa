class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_values = {}
        for i, val in enumerate(nums):
            diff = target - val
            if diff in seen_values:
                return [seen_values[diff] , i]
            else: 
                seen_values.update({val : i})
