class Solution {
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int r, int c){
        ocean[r][c] = 1;

        for(int i=0; i<4; i++){
            int nr = r + drow[i], nc = c + dcol[i];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() 
            && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                dfs(heights, ocean, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> pacific(row, vector<int> (col, 0));
        vector<vector<int>> atlantic(row, vector<int> (col, 0));

        for(int i=0; i<col; i++){
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, row - 1, i);
        }

        for(int i=0; i<row; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, col - 1);
        }

        vector<vector<int>> res;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
