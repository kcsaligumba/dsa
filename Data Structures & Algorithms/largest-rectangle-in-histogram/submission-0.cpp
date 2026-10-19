class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = heights[0];
        int l, r;

        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            l = i;
            while (l > 0 && heights[l - 1] >= height) {
                l--;
            }
            r = i;
            while (r < heights.size() && heights[r] >= height) {
                r++;
            }
            int currArea = height * (r - l);
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};
