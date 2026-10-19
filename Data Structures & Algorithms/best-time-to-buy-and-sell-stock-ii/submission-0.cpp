class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallSum = 0;
        int bigSum = 0;
        int currMin = 0;
        int left = 0;
        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] < prices[currMin]) {
                currMin = right;
            }
            if (prices[left] < prices[right]) {
                smallSum += prices[right] - prices[left];
            }
            bigSum = max(smallSum, prices[right] - prices[currMin]);
            left++;
        }
        return max(smallSum, bigSum);
    }
};