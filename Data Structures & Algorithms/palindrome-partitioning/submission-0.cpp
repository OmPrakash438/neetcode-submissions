class Solution {
public:
    bool isPalindrome(string pal){
        if(pal.size() == 1) return true;

        int st = 0, end = pal.size() - 1;
        while(st < end){
            if(pal[st] != pal[end]) return false;
            st++;
            end--;
        }

        return true;
    }

    void allPaths(string s, vector<vector<string>>& res, vector<string>& part, int idx){
        if(idx >= s.size()){
            res.push_back(part);
            return;
        }

        string pal = "";
        for(int i=idx; i<s.size(); i++){
            pal += s[i];

            if(isPalindrome(pal)){
                part.push_back(pal);
                allPaths(s, res, part, i+1);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;

        allPaths(s, res, part, 0);

        return res;
    }
};
