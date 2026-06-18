class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size());
        vector<int> prefix(nums.size());

        int pProduct = 1;
        for(int i=0; i<prefix.size(); i++){
            prefix[i] = pProduct;
            pProduct *= nums[i];
        }

        int sProduct = 1;
        for(int i=suffix.size() - 1; i >= 0; --i){
            suffix[i] = sProduct;
            sProduct *= nums[i];
        }

        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
