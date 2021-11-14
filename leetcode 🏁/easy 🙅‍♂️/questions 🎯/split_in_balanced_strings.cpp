// https://leetcode.com/problems/split-a-string-in-balanced-strings/

/**
 * Split in max no. of balanced strings
 **/

class Solution {
public:
    int balancedStringSplit(string s) {
        int ls=0;
        int rs=0;
        int res=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='R'){
                rs++;
            }else {
                ls++;
            }
            if(rs==ls && rs!=0) {
                res++;
                rs=0;
                ls=0;
            }
        }
        return res;
    }
};