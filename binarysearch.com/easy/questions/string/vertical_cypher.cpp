// https://binarysearch.com/problems/Vertical-Cipher

vector<string> solve(string s, int k) {
    if(s.length()==0) {
        return {};
    }
    vector<string> result(k, "");
    int ind=0;
    for(int i=0;i<s.length();i++) {
        result[ind]+=s[i];
        ind++;
        if(ind==k) {
            ind=0;
        }
    }
    return result;
}