class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            //Up
            if (r - 1 >= 0 && !vis[r - 1][c] && grid[r - 1][c] == '1') {
                vis[r - 1][c] = 1;
                q.push({r - 1, c});
            }

            // Right
            if (c + 1 < m && !vis[r][c + 1] && grid[r][c + 1] == '1') {
                vis[r][c + 1] = 1;
                q.push({r, c + 1});
            }

            // Down
            if (r + 1 < n && !vis[r + 1][c] && grid[r + 1][c] == '1') {
                vis[r + 1][c] = 1;
                q.push({r + 1, c});
            }

            // Left
            if (c - 1 >= 0 && !vis[r][c - 1] && grid[r][c - 1] == '1') {
                vis[r][c - 1] = 1;
                q.push({r, c - 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(r, vector<int> (c, 0));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return count;
    }
};
