class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = INT_MIN;
        unordered_set<char> freq;

        if(s.size() == 0) return 0;

        int l = 0, r = 0;

        while(l <= r && r <= s.size() - 1){
            if(freq.find(s[r]) == freq.end()){
                freq.insert(s[r]);
                r++;
                int currLength = r - l;
                length = max(length, currLength);
            }else{
                while(l <= r && freq.find(s[r]) != freq.end()){
                    freq.erase(s[l]);
                    l++;
                }
            }
        }
        
        return length;
    }
};
