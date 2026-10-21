class Solution {
public:
    void allSet(vector<int>& nums, vector<vector<int>>& res,
                vector<int>& subset, int idx) {

        res.push_back(subset);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            allSet(nums, res, subset, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> subset;

        allSet(nums, res, subset, 0);

        return res;
    }
};