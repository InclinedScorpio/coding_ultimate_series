// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        
        string stringToCheck = to_string(x);

        // logic
        int lastIndex = stringToCheck.length()-1;
        for(int i=0;i<stringToCheck.length();i++) {
            if(stringToCheck[i]!=stringToCheck[lastIndex--]){
                return false;
            }
        }
        return true;
    }
};