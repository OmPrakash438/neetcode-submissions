class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> m;

        for(int i=0; i<strs.size(); i++){
            vector<int> freq(26, 0);
            vector<string> group;
            string s = strs[i];

            for(int j=0; j<s.size(); j++){
                freq[s[j] - 'a']++;
            }

            string key = to_string(freq[0]);
            for(int i=1; i<26; i++){
                key += ',' + to_string(freq[i]);
            }

            m[key].push_back(s);
        }

        for(auto it : m){
            ans.push_back(it.second);
        }

        return ans;
    }
};
