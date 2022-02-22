// https://binarysearch.com/problems/Recurring-Character

int solve(string s) {
    set<char> store;
    for(int i=0;i<s.length();i++) {
        if(store.find(s[i])!=store.end()) {
            return i;
        }else {
            store.insert(s[i]);
        }
    }
    return -1;
}
