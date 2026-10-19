class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int mp = 0;
        
        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                mp = max(mp, prices[right] - prices[left]);
            }
            else {
                left = right;
            }
            right++;
        }
        
        return mp;
    }
};
