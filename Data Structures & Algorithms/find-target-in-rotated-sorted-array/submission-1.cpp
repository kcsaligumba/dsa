class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = nums.size() / 2;

        while (left != right) {
            if (nums[mid] == target) {
                return mid;
            }

            if (target > nums[mid]) { // Look for larger
                if (nums[mid] < nums[right] && target <= nums[right]) { // Go right
                    left = mid + 1;
                }
                else { // Go left
                    right = mid - 1;
                }
            }
            else { // Look for smaller
                if (nums[mid] > nums[right] && target <= nums[right]) { // Go right
                    left = mid + 1;
                }
                else { // Go left
                    right = mid - 1;
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
