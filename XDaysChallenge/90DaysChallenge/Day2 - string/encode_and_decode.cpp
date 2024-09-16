// https://neetcode.io/problems/string-encode-and-decode

/**
 * Simple problem
*/
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s: strs) {
            res+=(s + "|");
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0;i<s.length();i++) {
            string mys = "";
            while(s[i]!='|') {
                mys+=s[i];
                i++;
            }
            res.push_back(mys);
        }
        return res;
    }
};
