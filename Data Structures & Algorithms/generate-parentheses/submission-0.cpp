class Solution {
public:
    void allPaths(int n, int open, int close, vector<string>& res, string& combo){
        if(combo.size() == 2*n){
            res.push_back(combo);
            return;
        }

        if(open < n){
            combo += '(';
            allPaths(n, open + 1, close, res, combo);
            combo.pop_back();
        }

        if(close < open){
            combo += ')';
            allPaths(n, open, close + 1, res, combo);
            combo.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string combo;

        allPaths(n, 0, 0, res, combo);

        return res;
    }
};
