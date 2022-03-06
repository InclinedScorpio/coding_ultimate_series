// https://binarysearch.com/problems/Balanced-Brackets

/**
 * LOGIC: Stacks works best in brackets !
 * 
 * 
 */ 
bool solve(string s) {
    stack<char> store;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') {
            store.push('(');
        } else {
            if(!store.size()) return false;
            if('('==store.top()) {
                store.pop();
            } else {
                return false;
            }
        }
    }
    if(store.size()) return false;
    return true;
}