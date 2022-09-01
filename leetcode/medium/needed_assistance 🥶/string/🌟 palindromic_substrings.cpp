// https://leetcode.com/problems/palindromic-substrings/

/**
 * LOGIC: Need 2 things here
 * -1) First start from the ind and keep moving outwards
 * -2) Second start from the ind and ind+1 as this case won't be covered in 1)
 * 
 */ 
class Solution {
public:
    int countSubstrings(string s) {
        int counter=0;
        for(int i=0;i<s.length();i++) {
            counter+=helper(s, i, i);
            counter+=helper(s, i, i+1);
        }
        return counter;
    }
    
    int helper(string s, int left, int right) {
        int counter=0;
        while(left>=0 && right<=s.length()-1 && s[left]==s[right]) {
            counter++;
            left--;
            right++;
        } 
        return counter;
    }
};