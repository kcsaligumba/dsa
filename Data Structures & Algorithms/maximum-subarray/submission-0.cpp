class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = 0;
        for (int n : nums) {
            if (curSum < 0) curSum = 0;
            curSum += n;
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
