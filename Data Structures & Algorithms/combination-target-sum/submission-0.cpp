class Solution {
public:
    set<vector<int>> s;

    void combination(vector<int>& nums, vector<int>& combo, vector<vector<int>>& ans, int target, int idx){
        if(idx == nums.size() || target < 0) return;
        if(target == 0){
            if(s.find(combo) == s.end())
            ans.push_back(combo);
            s.insert(combo);
            return;
        }

        combo.push_back(nums[idx]);
        combination(nums, combo, ans, target - nums[idx], idx + 1);
        combination(nums, combo, ans, target - nums[idx], idx);

        combo.pop_back();
        combination(nums, combo, ans, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combo;
        vector<vector<int>> ans;

        combination(nums, combo, ans, target, 0);

        return ans;
    }
};
