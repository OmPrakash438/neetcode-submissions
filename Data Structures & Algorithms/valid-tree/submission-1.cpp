class Solution {
public:
    bool dfs(vector<int> adjLs[], vector<int>& vis, int par, int node){
        vis[node] = 1;

        for(auto it : adjLs[node]){
            if(!vis[it]){
                if(dfs(adjLs, vis, node, it)){
                    return true;
                }
            }
            else if(it != par){
                return true;
            }
        }

        return false;
    }

    bool isCycle(vector<int> adjLs[], vector<int>& vis, int n){
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(adjLs, vis, -1, i)){
                    return true;
                }
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n - 1){
            return false;
        }

        vector<int> adjLs[n];
        vector<int> vis(n, 0);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }

        if(isCycle(adjLs, vis, n)){
            return false;
        }

        return true;
    }
};