class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int res = 0;
        int l = 0, maxf = 0;

        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            maxf = max(maxf, m[s[i]]);

            while ((i - l + 1 ) - maxf > k){
                m[s[l]]--;
                l++;
            }

            res = max(res, i - l + 1);
        }

        return res;
    }
};
