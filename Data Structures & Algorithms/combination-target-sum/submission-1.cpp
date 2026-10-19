class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, {}, nums, target);
        return res;
    }

    void dfs(int index, vector<int> path, vector<int> nums, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (index >= nums.size() || target < 0) {
            return;
        }
        path.push_back(nums[index]);
        dfs(index, path, nums, target - nums[index]);
        path.pop_back();
        dfs(index + 1, path, nums, target);
    }
};
