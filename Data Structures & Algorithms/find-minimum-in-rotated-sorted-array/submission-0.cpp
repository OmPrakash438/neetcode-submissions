class Solution {
public:
    int findMin(vector<int> &nums) {
        int st = 0;
        int end = nums.size() - 1;
        int mid;

        while(st < end){
            mid = st + (end - st)/2;

            if(nums[mid] < nums[end]){
                end = mid;
            }else{
                st = mid + 1;
            }
        }

        return nums[st];
    }
};
