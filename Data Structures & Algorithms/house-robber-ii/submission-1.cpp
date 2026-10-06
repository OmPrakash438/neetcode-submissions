class Solution {
public:
    int allPaths(vector<int>& nums, vector<int>& dp, int idx, int end){
        if(idx < end) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + allPaths(nums, dp, idx-2, end);
        int notPick = allPaths(nums, dp, idx-1, end);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp01(n, -1);
        vector<int> dp02(n, -1);

        int first = allPaths(nums, dp01, n-2, 0);
        int second = allPaths(nums, dp02, n-1, 1);

        return max(first, second);
    }
};
