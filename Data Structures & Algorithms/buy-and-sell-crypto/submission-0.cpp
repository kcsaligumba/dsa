class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Brute Force
        int mp = 0;
        for (int buy = 0; buy < prices.size(); buy++) {
            for (int sell = buy + 1; sell < prices.size(); sell++) {
                mp = max(mp, prices[sell] - prices[buy]);
            }
        }
        return mp;
    }
};
