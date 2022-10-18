// https://leetcode.com/problems/longest-palindrome/

/**
 * LOGIC: Basic question, just understand that palindrome can be created only if 2 same item exists
 * - And if it's paldindrome length will be odd if there exists some odd length character.
 * 
 */ 
class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> store;
        for(char a: s) {
            store[a]++;
        }
        
        // check duals
        int length=0;
        bool isOneExists=false;
        for(auto s: store) {
            if(s.second%2!=0) isOneExists=true;
            length+=(s.second/2)*2;
        }
        return length+isOneExists;
    }
};
        