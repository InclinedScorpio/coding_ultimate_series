// https://leetcode.com/problems/longest-substring-without-repeating-characters

/**
 * Problem requires basic logic of using two pointers to traverse the string
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mapper;
        int l=0, r=0, result=0;
        while(r<s.length()) {
            if(mapper.find(s[r])!=mapper.end()) {
                while(l<=mapper[s[r]]) {
                    mapper.erase(s[l]);
                    l++;
                }
                mapper.erase(s[r]);
                mapper[s[r]]=r;
                r++;
            } else {
                mapper[s[r]] = r;
                result = max(result, r-l+1);
                r++;
            }
        }
        return result;
    }
};