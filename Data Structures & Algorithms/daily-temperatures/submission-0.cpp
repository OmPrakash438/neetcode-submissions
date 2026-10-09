class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);

        stack<pair<int, int>> st;
        st.push({temp[0], 0});

        for(int i=1; i<n; i++){
            auto res = st.top();

            while(temp[i] > res.first && !st.empty()){
                int days = i - res.second;
                st.pop();
                ans[res.second] = days;

                if(!st.empty()) res = st.top();
            }

            st.push({temp[i], i});
        }

        return ans;
    }
};
