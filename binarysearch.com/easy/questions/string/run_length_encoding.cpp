// https://binarysearch.com/problems/Run-Length-Encoding

string solve(string s) {
    string str="";
    int count=1;
    char lastChar=s[0];
    for(int i=1;i<s.length();i++) {
        if(s[i]==lastChar) {
            count++;
            continue;
        }
        str+=to_string(count) + lastChar;
        count=1;
        lastChar = s[i];
    }
        str+=to_string(count) + lastChar;
        return str;
}