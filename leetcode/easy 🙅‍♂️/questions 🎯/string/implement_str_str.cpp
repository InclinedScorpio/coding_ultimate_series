// https://leetcode.com/problems/implement-strstr/


/**
 * string::npos -> returns max value of string
 * find() returns the index of the substring 
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == "" && needle == "") {
            return 0;
        }
        int result = haystack.find(needle);
        if(result == string::npos) {
            return -1;
        }
        return result;
    }
};