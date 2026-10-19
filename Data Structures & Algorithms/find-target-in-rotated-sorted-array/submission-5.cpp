class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = nums.size() / 2;

        while (left < right) {
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) { // Pivot is to the right
                if (target < nums[left] || target > nums[mid]) { // Go right
                    left = mid + 1;
                }
                else { // Go left
                    right = mid - 1;
                }
            }
            else if (nums[mid] <= nums[right]) { // Pivot is to the left
                if (target > nums[right] || target < nums[mid]) { // Go left
                    right = mid - 1;
                }
                else { // Go right
                    left = mid + 1;
                }
            }

            mid = (right + left) / 2;
        }

        if (nums[mid] == target) {
            return mid;
        }

        return -1;
    }
};
