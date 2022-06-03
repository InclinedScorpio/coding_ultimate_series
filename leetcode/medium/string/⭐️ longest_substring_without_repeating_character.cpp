// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/**
 * LOGIC: It can be done using unordered_set
 * - But that would give O(2N) as both left and right will traverse
 * 
 * 
 * - To do it in O(N) - you can simply use map and store the index of char where occured
 * - And if repeated, just bring left forward to that index+1 where already char is there
 * - This will help it in reducing O(N)
 * 
 * ALTERNATIVE: Use Sliding Window Approach! @see unique_string problem
 * 
 * COMPLEXITY: O(N) 
 * SPACE: O(256) - As all chars, num, symbol all allowed 
 * 
 */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> store;
        int maxRes=s.length()>0?1:0;
        
        int left=0, right=1;
        store[s[left]]=0;
        
        while(right<s.length()) {
            if(store.count(s[right]) && store[s[right]]>=left) {
                left = store[s[right]] + 1;
            }
            store[s[right]] = right;
            if((right-left+1) > maxRes) maxRes = right - left + 1;
            right++;
        }
        return maxRes;
    }
};