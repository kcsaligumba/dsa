class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        int left;
        int right;
        while (i < nums.size() - 2) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (left < nums.size() - 1 && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else{
                    right--;
                }
            }

            i++;
            while (i < nums.size() - 1 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return res;
    }
};
