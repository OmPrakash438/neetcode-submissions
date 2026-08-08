class Solution {
public:
    int ROW, COL;
    set<pair<int, int>> path;

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int idx){
        if(idx == word.size()) return true;

        if(r < 0 || c < 0 || r >= ROW || c >= COL || board[r][c] != word[idx] ||        path.count({r, c})){
            return false;
        }

        path.insert({r, c});
        bool ans = dfs(board, word, r, c - 1, idx + 1) ||
                   dfs(board, word, r, c + 1, idx + 1) ||
                   dfs(board, word, r + 1, c, idx + 1) ||
                   dfs(board, word, r - 1, c, idx + 1);

        path.erase({r, c});

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
