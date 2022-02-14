// https://binarysearch.com/problems/Compress-String

string solve(string s) {

    map<char, int> store;
    string result="";
    char lastOcur=s[0];
    result=s[0];
    for(int i=1;i<s.length();i++) {
        if(s[i]==lastOcur) {
            continue;
        }
        result+=s[i];
        lastOcur = s[i];
    }
    return result;
    
}