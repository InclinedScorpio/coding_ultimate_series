// https://leetcode.com/problems/isomorphic-strings/

/**
 * LOGIC: Use 2 maps. Finding map is O(1) - leverage it
 * 
 * 
 * 
 */ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
                
        map<char, char> first;
        map<char, char> second;
        for(int i=0;i<s.length();i++) {
            if(first.find(s[i])!=first.end()) {
                // check already existing
                if(first[s[i]]!=t[i]) {
                    return false;
                }
            }else {
                first[s[i]] = t[i];
            }
            if(second.find(t[i])!=second.end()) {
                // check already existing
                if(second[t[i]]!=s[i]) {
                    return false;
                }
            }else {
                second[t[i]] = s[i];
            }
        }
        return true;
    }
};