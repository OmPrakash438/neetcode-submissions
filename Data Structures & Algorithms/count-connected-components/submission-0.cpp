class Solution {
public:
    void dfs(vector<int> adjLs[], vector<int>& vis, int node){
        vis[node] = 1;

        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(adjLs, vis, it);
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adjLs[n];
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adjLs, vis, i);
                count++;
            };
        }

        return count;
    }
};
