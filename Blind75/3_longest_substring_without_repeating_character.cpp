// https://leetcode.com/problems/longest-substring-without-repeating-characters/description

/**
 * 
 * LOGIC: Just need to think about hashing here
 * as we just need a set to keep a window and keep checking
 * with 2 pointers maintaining the window size
 * 
 * right will add to set and left will remove
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> seen;

        int left=0, right=0;

        int result=0;

        while(right<s.length()) {
            if(seen.find(s[right])!=seen.end()) {
                // already there - move left
                while(left<s.length() && s[left]!=s[right]) {
                    seen.erase(s[left]);
                    left++;
                }
                left++;
                right++;
                continue;
            }
            // not there
            seen.insert(s[right]);
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};