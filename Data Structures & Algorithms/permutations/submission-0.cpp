class Solution {
public:
    void allPaths(vector<int>& nums, vector<vector<int>>& res, vector<int>& combo, vector<int>& vis){
        if(combo.size() == nums.size()){
            res.push_back(combo);
            return;
        }

        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                vis[i] = 1;

                combo.push_back(nums[i]);
                allPaths(nums, res, combo, vis);
                combo.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> combo;
        vector<int> vis(nums.size(), 0);

        allPaths(nums, res, combo, vis);

        return res;
    }
};
