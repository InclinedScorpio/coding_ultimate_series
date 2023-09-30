// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/**
 * Question requires only understanding of sliding window and hashmap
 * 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, currRes=0, maxSeen=0;
        unordered_set<int> store;
        while(r<s.length()) {
            if(store.find(s[r])==store.end()) {
                store.insert(s[r]);
                currRes++;
                maxSeen = max(maxSeen, currRes);
                r++;
            } else {
                while(s[l]!=s[r]) {
                    store.erase(s[l]);
                    l++;
                    currRes--;
                }
                store.erase(s[l]);
                l++;
                currRes--;
            }
        }
        return maxSeen;
    }
};