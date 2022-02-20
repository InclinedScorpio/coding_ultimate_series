// https://binarysearch.com/problems/Noisy-Palindrome

bool solve(string s) {
    string str = "";
    for(int i=0;i<s.length();i++) {
        if(islower(s[i])) {
            str+=s[i];
        }
    }
    cout<<str;
    string revStr = str;
    reverse(str.begin(), str.end());
    return str==revStr;
}