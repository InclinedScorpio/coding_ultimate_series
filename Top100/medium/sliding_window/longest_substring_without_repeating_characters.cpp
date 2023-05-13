// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/**
 * Sliding window problem
 * 
 */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int l=0, r=1;
        int longestSubstring = 1;
        unordered_map<char, int> store;

        store[s[0]]++;
        while(r<s.length()) {
            longestSubstring = max(r-l,longestSubstring);
            if(store.find(s[r])!=store.end()) {
                // already existing, start moving left
                while(s[l]!=s[r]) {
                    store[s[l]]--;
                    if(store[s[l]]<=0) {
                        store.erase(s[l]);
                    }
                    l++;
                }
                store[s[l]]--;
                if(store[s[l]]<=0) {
                    store.erase(s[l]);
                }
                l++;
            }
                store[s[r]]++;
                r++;
        }
        longestSubstring = max(r-l,longestSubstring);
        return longestSubstring;
    }
};