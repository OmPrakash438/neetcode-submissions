class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row, col;
        map<pair<int, int>, unordered_set<int>> box;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                pair<int, int> boxKey = {i / 3, j / 3};
                if (row[i].count(board[i][j]) || col[j].count(board[i][j]) ||                    box[boxKey].count(board[i][j])){
                    return false;
                }

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[boxKey].insert(board[i][j]);
            }
        }

        return true;
    }
};
