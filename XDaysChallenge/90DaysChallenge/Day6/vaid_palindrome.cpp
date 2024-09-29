// https://leetcode.com/problems/valid-palindrome/description/

/**
 * Simple problem, requires understanding of string manipulation
 * tolower gives lowercase of a character in ascii.
 * isalpha - check if it is alphabet
 * isdigit - check if it is digit
 */
class Solution {
public:
    bool isPalindrome(string s) {
        // remove space
        // keep alpha num
        // lowercase all of them
        // 65 - 'A' +26
        // 97 - 'a' -> 122
        // lower than 97, so add (97-65) -> 32 to it
        // numbers - 48 to 57

        string stringToCheck = "";
        for(char a: s) {
            int intofa = (int)a;
            if(intofa>=97 && intofa<=122) {
                stringToCheck+=a;
            } else if(intofa>=65 && intofa<=90) {
                stringToCheck+=(char)tolower(a);
            } else if(intofa>=48 && intofa<=57) {
                stringToCheck+=a;
            }
        }

        for(int i=0;i<stringToCheck.length();i++) {
            if(stringToCheck[i]!=stringToCheck[stringToCheck.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};