class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        int left = 0;
        int right = heights.size() - 1;
        int area;

        while (left < right) {
            area = (right - left) * min(heights[left], heights[right]);
            maxA = max(maxA, area);

            if (heights[left] <= heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxA;
    }
};
