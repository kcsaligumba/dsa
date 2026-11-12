import bisect

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start, end = bisect.bisect_left(nums, target), bisect.bisect_right(nums, target)
        return [-1, -1] if (start not in range(len(nums)) or 
                            nums[start] != target) else [start, end - 1]