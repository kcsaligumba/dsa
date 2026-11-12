import bisect

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start, end = -1, -1
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (right + left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        if left not in range(len(nums)) or nums[left] != target:
            return [-1, -1]
        start = left

        left, right = 0, len(nums) - 1
        while left < right:
            mid = (right + left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid
        end = left if left in range(len(nums)) and nums[left] == target else left - 1

        return [start, end]