class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j];
                if (rows[i].count(val)) {
                    return false;
                }
                if (cols[j].count(val)) {
                    return false;
                }
                if (squares[{i / 3, j / 3}].count(val)) {
                    return false;
                }
                rows[i].insert(val);
                cols[j].insert(val);
                squares[{i / 3, j / 3}].insert(val);
            }
        }
        return true;
    }
};
