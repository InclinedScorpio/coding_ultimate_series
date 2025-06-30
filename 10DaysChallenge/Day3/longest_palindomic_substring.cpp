// https://leetcode.com/problems/longest-palindromic-substring

/**
 * 
 * Blind 75 Problem
 * Longest Palindromic Substring
 * Sliding window problem
 * 
 * 2 cases to handle
 * 1. odd length palindrome
 * 2. even length palindrome
 * * For each character, we will try to expand around it for both cases
 * * Time Complexity: O(n^2)
 * * Space Complexity: O(1)
 */

class Solution {
    public:
        string longestPalindrome(string s) {
            int result=0;
            string str="";
            for(int i=0;i<s.length();i++) {
                
                int left=i-1;
                int right=i+1;
                int counter=1;
    
                // odd length
                while(left>=0 && right<s.length() && s[left]==s[right]) {
                    left--;
                    right++;
                    counter+=2;
                }
                left++;
                right--;
                if(counter>result) {
                    str=s.substr(left, (right-left+1));
                    result = counter;
                }
    
    
                // even length
                left=i;
                right=i+1;
                counter=0;
                while(left>=0 && right<s.length() && s[left]==s[right]) {
                    left--;
                    right++;
                    counter+=2;
                }
                left++;
                right--;
                if(counter>result) {
                    str=s.substr(left, (right-left+1));
                    result = counter;
                }
            }
            return str;
        }
    };