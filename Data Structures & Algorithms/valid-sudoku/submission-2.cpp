class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> digits;
        int n = board.size(), m = board[0].size();
        // check rows
        for (int r = 0; r < n; r++) { // for every row
            digits.clear();
            for (int c = 0; c < m; c++) { // for every column
                char d = board[r][c];
                if (digits.contains(d)) {
                    return false;
                }
                if (d != '.') {
                    digits.insert(d);
                }
            }
        }
        // check columns
        for (int c = 0; c < m; c++) { // for every column
            digits.clear();
            for (int r = 0; r < n; r++) { // for every row
                char d = board[r][c];
                if (digits.contains(d)) {
                    return false;
                }
                if (d != '.') {
                    digits.insert(d);
                }
            }
        }
        // check 3x3
        for (int r = 0; r < n; r += 3) {
            for (int c = 0; c < m; c += 3) {
                digits.clear();
                for (int i = r; i < r + 3; i++) {
                    for (int j = c; j < c + 3; j++) {
                        char d = board[i][j];
                        if (digits.contains(d)) {
                            return false;
                        }
                        if (d != '.') {
                            digits.insert(d);
                        }
                    }
                }
            }
        }
        return true;
    }
};
