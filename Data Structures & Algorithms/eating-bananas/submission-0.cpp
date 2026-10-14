class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int st = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(st <= end){
            double mid = st + (end - st)/2;

            long long hour = 0;
            for(int i=0; i<n; i++){
                hour += ceil(piles[i]/mid);
            }

            if(hour <= h){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }

        return ans;
    }
};
