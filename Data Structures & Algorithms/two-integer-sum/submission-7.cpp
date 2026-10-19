class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff_to_idx;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (diff_to_idx.contains(diff)) {
                return {diff_to_idx[diff], i};
            }

            diff_to_idx[nums[i]] = i;
        }

        return {};
    }
};
