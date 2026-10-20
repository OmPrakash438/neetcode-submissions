class Solution {
public:
    void allSubsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int idx){
        if(idx >= nums.size()){
            res.push_back(subset);
            return ;
        }

        subset.push_back(nums[idx]);
        allSubsets(nums, res, subset, idx + 1);
        subset.pop_back();
        allSubsets(nums, res, subset, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        allSubsets(nums, res, subset, 0);

        return res;
    }
};
