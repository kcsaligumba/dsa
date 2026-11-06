class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (right + left) // 2
            if nums[mid] > nums[right]:
                # pivot is on the right
                left = mid + 1
            else:
                # pivot is on the left
                right = mid
        
        return nums[left]