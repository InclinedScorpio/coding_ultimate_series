// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxLen=0;
        unordered_set<int> store;

        while(r<s.length()){
            if(store.find(s[r])!=store.end()) {
                while(s[l]!=s[r]) {
                    store.erase(s[l]);
                    l++;
                }
                store.erase(s[l]);
                l++;
            }
            store.insert(s[r]);
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
