class Solution {
    unordered_map<int, string> keypad = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

public:
    void allPaths(string digits, vector<string>& res, string& letter, int idx){
        if(idx >= digits.size()){
            res.push_back(letter);
            return;
        }

        int num = digits[idx] - '0';
        string alphabets = keypad[num];

        for(int i=0; i<alphabets.size(); i++){
            letter.push_back(alphabets[i]);
            allPaths(digits, res, letter, idx + 1);
            letter.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> res;
        string letter;

        allPaths(digits, res, letter, 0);

        return res;
    }
};
