// https://binarysearch.com/problems/Consecutive-Duplicates

string solve(string s) {
    if(!s.length()) return s;
    string str = "";
    str+=s[0];
    for(int i=1;i<s.length();i++)
        if(s[i]!=s[i-1]) str+=s[i];
    return str;
}