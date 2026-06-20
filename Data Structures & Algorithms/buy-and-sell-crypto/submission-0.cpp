class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;

        for(int i=0; i<prices.size(); i++){
            buy = min(buy, prices[i]);
            int currProfit = prices[i] - buy;

            profit = max(currProfit, profit);
        }

        return profit;
    }
};
