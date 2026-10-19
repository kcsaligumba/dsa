class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left = 0;
        int max;

        for (int right = k - 1; right < nums.size(); right++) {
            max = *max_element(nums.begin() + left, nums.begin() + right + 1);
            res.push_back(max);

            left++;
        }

        return res;
    }
};
