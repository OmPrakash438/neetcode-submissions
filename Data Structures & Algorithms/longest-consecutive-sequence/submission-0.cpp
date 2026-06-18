class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest = 0;

        for(int it : nums){
            s.insert(it);
        }

        for(int it : s){
            if(s.find(it - 1) == s.end()){
                int length = 1;
                while(s.find(it + length) != s.end()) length++;
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
