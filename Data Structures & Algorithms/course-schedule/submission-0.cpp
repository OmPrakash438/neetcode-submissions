class Solution {
public:
    bool dfs(vector<int> adjLs[], vector<int>& vis, vector<int>& pathVis, int node){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adjLs[node]){
            if(!vis[it]){
                if(dfs(adjLs, vis, pathVis, it)){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool isCycle(int V, vector<int> adjLs[], vector<int>& vis, vector<int>& pathVis){
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(adjLs, vis, pathVis, i)){
                    return true;
                }
            }
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> adjLs[numCourses];
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0; i<n; i++){
            adjLs[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return !(isCycle(numCourses, adjLs, vis, pathVis));
    }
};
