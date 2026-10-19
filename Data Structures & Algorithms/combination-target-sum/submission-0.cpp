class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, {}, 0, nums, target);
        return res;
    }

    void dfs(int index, vector<int> path, int total, vector<int> nums, int target) {
        if (total == target) {
            res.push_back(path);
            return;
        }
        if (index >= nums.size() || total > target) {
            return;
        }
        path.push_back(nums[index]);
        dfs(index, path, total + nums[index], nums, target);
        path.pop_back();
        dfs(index + 1, path, total, nums, target);
    }
};
