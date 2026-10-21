class Solution {
public:
    void allSum(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combo, int idx, int target){
        if(target == 0){
            res.push_back(combo);
            return;
        }

        if(target < 0 || idx >= candidates.size()) return;

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            combo.push_back(candidates[i]);
            allSum(candidates, res, combo, i + 1, target - candidates[i]);
            combo.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combo;

        sort(candidates.begin(), candidates.end());

        allSum(candidates, res, combo, 0, target);

        return res;
    }
};
