class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        if (word.length() > board.size() * board[0].size()) return false;
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    res = (res || search(board, {i, j}, {-1, -1}, word, 1));
                }
            }
        }

        return res;
    }

    bool search(const vector<vector<char>>& board, pair<int, int> coord, pair<int, int> prev, string word, int idx) {
        if (idx >= word.length()) return true;
        int row = coord.first;
        int col = coord.second;
        bool res = false;
        if (row > 0 && row - 1 != prev.first && board[row - 1][col] == word[idx]) {
            res = (res || search(board, {row - 1, col}, {row, col}, word, idx + 1));
        }
        if (row < board.size() - 1 && row + 1 != prev.first && board[row + 1][col] == word[idx]) {
            res = (res || search(board, {row + 1, col}, {row, col}, word, idx + 1));
        }
        if (col > 0 && col - 1 != prev.second && board[row][col - 1] == word[idx]) {
            res = (res || search(board, {row, col - 1}, {row, col}, word, idx + 1));
        }
        if (col < board[row].size() - 1 && col + 1 != prev.second && board[row][col + 1] == word[idx]) {
            res = (res || search(board, {row, col + 1}, {row, col}, word, idx + 1));
        }
        return res;
    }
};
