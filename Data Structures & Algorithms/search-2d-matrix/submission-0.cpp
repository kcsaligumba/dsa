class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int top = 0;
        int down = matrix.size() - 1;

        while (top <= down) {
            int midVertical = (top + down) / 2;
            if (target < matrix[midVertical][0]) {
                down = midVertical - 1;
                continue;
            }
            if (target > matrix[midVertical][n - 1]) {
                top = midVertical + 1;
                continue;
            }

            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int midHorizontal = (left + right) / 2;
                if (target == matrix[midVertical][midHorizontal]) return true;
                if (target < matrix[midVertical][midHorizontal]) right = midHorizontal - 1;
                else left = midHorizontal + 1;
            }

            break;
        }

        return false;
    }
};
