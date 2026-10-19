class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> diff_to_idx;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if (diff_to_idx.contains(diff)) {
                return {diff_to_idx[diff], i};
            }

            diff_to_idx[nums[i]] = i;
        }

        return {};
    }
};
