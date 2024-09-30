// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/**
 * Keep a window and move left pointer when you have matching character!
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // resets as soon as left sees matched one
        int left=0, right=0;
        int maxResult=0;
        unordered_set<char> store;
        while(right<s.length()) {
            if(store.find(s[right])==store.end()) {
                maxResult = max(maxResult, (right-left+1));
            } else {
                // shift left till we remove matched one
                while(s[left]!=s[right]) {
                    store.erase(s[left++]);
                }
                store.erase(s[left++]); //matched removed
            }
            store.insert(s[right]);
            right++;
        }
        return maxResult;
    }
};