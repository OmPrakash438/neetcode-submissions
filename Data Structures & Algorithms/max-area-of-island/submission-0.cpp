class Solution {
public:
    int islandArea(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        int cover = 0;

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto cell = q.front();
            int r = cell.first;
            int c = cell.second;

            q.pop();

            cover++;

            if(r+1 < m && grid[r+1][c] == 1 && vis[r+1][c] == 0){
                q.push({r+1, c});
                vis[r+1][c] = 1;
            }

            if(r-1 >=0 && grid[r-1][c] == 1 && vis[r-1][c] == 0){
                q.push({r-1, c});
                vis[r-1][c] = 1;
            }

            if(c+1 < n && grid[r][c+1] == 1 && vis[r][c+1] == 0){
                q.push({r, c+1});
                vis[r][c+1] = 1;
            }

            if(c-1 >= 0 && grid[r][c-1] == 1 && vis[r][c-1] == 0){
                q.push({r, c-1});
                vis[r][c-1] = 1;
            }
        }

        return cover;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxArea = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int area = islandArea(grid, vis, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
