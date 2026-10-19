class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = nums.size() / 2;

        while (nums[right] < nums[left]) {
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
            mid = (right + left) / 2;
        }

        return nums[left];
    }
};
