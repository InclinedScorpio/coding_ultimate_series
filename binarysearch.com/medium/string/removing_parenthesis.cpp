// https://binarysearch.com/problems/Removing-Parentheses

/**
 * LOGIC: Basic, just use stack for () related questions
 * - Rest is basic logic here.
 * 
 */ 
int solve(string s) {

    stack<char> store;
    int result=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') store.push('(');
        else {
            if(store.empty()) {
                result++;
            } else if(store.top()=='(') {
                store.pop();
            }
        }
    }
    if(!store.empty()) result+=store.size();
    return result;
}