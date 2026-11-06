class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (right + left) // 2
            if nums[mid] == target:
                return True
            
            if nums[mid] > nums[right]:
                # pivot is on the right
                if nums[left] <= target < nums[mid]:
                    # search left
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[mid] < nums[right]:
                # pivot is on the left
                if nums[mid] < target <= nums[right]:
                    # search right
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                right -= 1
        
        return False