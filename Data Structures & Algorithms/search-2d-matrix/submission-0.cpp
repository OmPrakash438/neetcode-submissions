class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end = m - 1;
        int row = 0;
        while(st <= end){
            int mid = st + (end - st)/2;

            if(target >= matrix[mid][0]){
                row = mid;
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        st = 0, end = n -1;
        while(st <= end){
            int mid = st + (end - st)/2;

            if(target == matrix[row][mid]) return true;
            
            if(target > matrix[row][mid]) st = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};