// https://binarysearch.com/problems/String-Isomorphism

bool solve(string s, string t) {
    if(s.length()!=t.length()) return false;
    map<int,int> sTot, tToS;
    for(int i=0;i<s.length();i++) {
        if(sTot.find(s[i])!=sTot.end()) {
            if(sTot[s[i]]!=t[i]) return false;
        } else {
            sTot[s[i]]=t[i];
        }
        if(tToS.find(t[i])!=tToS.end()) {
            if(tToS[t[i]]!=s[i]) return false;
        } else {
            tToS[t[i]]=s[i];
        }
    }
    return true;
}