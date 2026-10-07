class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int st = 0;
        int end = n - 1;

        while(st <= end){
            int num = numbers[st] + numbers[end];

            if(num == target){
                return {st+1, end+1};
            }else if(num > target){
                end--;
            }else{
                st++;
            }
        }

        return {-1, -1};
    }
};
