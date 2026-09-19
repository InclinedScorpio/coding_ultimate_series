// https://leetcode.com/problems/valid-parentheses/

class Solution {
private:
        unordered_map<char, char> keeper = {{'}', '{'}, {']', '['}, {')', '('}};
public:
    bool checker(stack<char>& store, char& incoming) {
        if(store.empty() || store.top()!=keeper[incoming]) return false;
        store.pop();
        return true;
    }

    bool isValid(string s) {
        stack<char> store;
        
        for(int i=0;i<s.length();i++) {
            if(keeper.find(s[i])==keeper.end()) {
                store.push(s[i]);
            } else {
                if(!this->checker(store, s[i])) return false;
            }
        }
        return store.size()==0;
    }
};