// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> storeParam;
        
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                storeParam.push(s[i]);
            }else {
                if(storeParam.empty()) {
                    return false;
                }
                if(
                    (s[i]==')' && storeParam.top()=='(')
                   || (s[i]==']' && storeParam.top()=='[')
                   || (s[i]== '}' && storeParam.top()=='{')
                    ) {
                    storeParam.pop();
                    continue;
                }
                return false;
            }
        }
        if(storeParam.empty()) {
            return true;
        }
        return false;
    }
};