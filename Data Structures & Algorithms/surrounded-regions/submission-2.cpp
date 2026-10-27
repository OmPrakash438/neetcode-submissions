class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();

        board[i][j] = '#';

        if(i+1 < m && board[i+1][j] == 'O') dfs(board, i+1, j);
        if(i-1 >= 0 && board[i-1][j] == 'O') dfs(board, i-1, j);
        if(j+1 < n && board[i][j+1] == 'O') dfs(board, i, j+1);
        if(j-1 >= 0 && board[i][j-1] == 'O') dfs(board, i, j-1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            if(i == 0 || i == m-1){
                for(int j=0; j<n; j++){
                    if(board[i][j] == 'O') dfs(board, i, j);
                }
            }else{
                if(board[i][0] == 'O') dfs(board, i, 0);
                if(board[i][n-1] == 'O') dfs(board, i, n-1);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
