class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;

        for(int i=0; i<s.size(); i++){
            bracket.push(s[i]);

            if(bracket.top() == '}'){
                bracket.pop();
                if(bracket.empty()) return false;
                if(bracket.top() != '{') return false;
                else{
                    bracket.pop();
                    continue;
                }
            }
            if(bracket.top() == ']'){
                bracket.pop();
                if(bracket.empty()) return false;
                if(bracket.top() != '[') return false;
                else{
                    bracket.pop();
                    continue;
                }
            }
            if(bracket.top() == ')'){
                bracket.pop();
                if(bracket.empty()) return false;
                if(bracket.top() != '(') return false;
                else{
                    bracket.pop();
                    continue;
                }
            }
        }

        if(!bracket.empty()) return false;
        else return true;
    }
};
