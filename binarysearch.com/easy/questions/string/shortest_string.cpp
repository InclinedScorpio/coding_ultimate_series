// https://binarysearch.com/problems/Shortest-String

int solve(string s) {
    int one=0, zero=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='1') {
            one++;
        } else {
            zero++;
        }
    }

    return s.length() - ((min(one, zero))*2);
}