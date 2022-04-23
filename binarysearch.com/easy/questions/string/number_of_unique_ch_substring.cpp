// https://binarysearch.com/problems/Number-of-Unique-Character-Substrings

int solve(string s) {
    int count=0;
    for(int i=0;i<s.length();i++) {
        set<char> store;
        for(int j=i;j<s.length();j++) {
            store.insert(s[j]);
            if(store.size()<=1) {
                count++;
            } else {
                break;
            }
        }
    }
    return count;
}
