class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Brute Force
        int ma = 0;
        for (int i = 0; i < heights.size() - 1; i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                int area = (j - i) * min(heights[i], heights[j]);
                ma = max(ma, area);
            }
        }

        return ma;
    }
};
