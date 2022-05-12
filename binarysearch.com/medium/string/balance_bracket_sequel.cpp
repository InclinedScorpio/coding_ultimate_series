https://binarysearch.com/problems/Balanced-Brackets-Sequel

/**
 * LOGIC: Basic stack question
 * 
 */ 
bool solve(string s) {
    stack<char> store;

    for(int i=0;i<s.length();i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            store.push(s[i]);
        } else {
            if(!store.size()) return false;
            if(s[i]==')' && store.top()=='(') {
                store.pop();
            } else if(s[i]=='}' && store.top()=='{') {
                store.pop();
            } else if(s[i]==']' && store.top()=='[') {
                store.pop();
            } else {
                return false;
            }
        }
    }
    if(store.size()) return false;
    return true;
}