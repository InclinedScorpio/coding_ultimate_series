// https://leetcode.com/problems/longest-palindromic-substring/

/**
 * @see @find_all_possible_palindrome.cpp (algorithm > string) for clarity
 * LOGIC: Use DP and logic X___X i.e...
 * - If first and last char are equal &
 * - ___ is palindrome then complete string is palindrome
 * - For ___ part we can use DP using 2D Array
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    string longestPalindrome(string s) {    
        if(s.length()==0) return "";
        if(s.length()==1) return s;
        
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length()));
        int currMax=INT_MIN;
        int maxStart=0, maxSize=0;
        for(int outer=0;outer<s.length();outer++) {
            for(int i=0;i<s.length()-outer;i++) {
                int j = i+outer;
                if(i>j) continue;
                if(i==j) {
                    isPalindrome[i][j]=true;
                    // currMax = max(j+1, currMax);
                    if((j-i+1)>currMax) {
                        currMax=(j-i+1);
                        maxStart=i;
                        maxSize=(j-i+1);
                    }
                }else if(j==i+1 && s[i]==s[j]) {
                    isPalindrome[i][j]=true;
                    if((j-i+1)>currMax) {
                        currMax=(j-i+1);
                        maxStart=i;
                        maxSize=(j-i+1);
                    }
                } else if (j>i+1) {
                    if(s[i]==s[j] && isPalindrome[i+1][j-1]) {
                        isPalindrome[i][j]=true;
                        if((j-i+1)>currMax) {
                        currMax=(j-i+1);
                        maxStart=i;
                        maxSize=(j-i+1);
                    }
                    }
                }
            }
        }
        return s.substr(maxStart, maxSize);
    }
};