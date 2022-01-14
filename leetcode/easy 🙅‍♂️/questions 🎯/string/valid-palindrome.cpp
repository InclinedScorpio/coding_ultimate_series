// https://leetcode.com/problems/valid-palindrome/

/**
 * LOGIC: Knowing Ascii codes and using it to change case of character
 * - A:65, B:90
 * - a:97, z:122
 * - 0:48, 9:57
 * 
 * - To change upper to lower...
 * - uppercase + 32(difference of A and a)
 * 
 */ 
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> store;
        for(int i=0;i<s.length();i++) {
            int current = s[i];
            cout<<"curr-"<<current<<endl;
            if(current>=65 && current<=90) {
                char upperCase = current+32;
                store.push_back(upperCase);
            }else if(
                    (current>=97 && current<=122) ||
                    (current>=48 && current<=57)
            ) {
                store.push_back(s[i]);
            }
        }
        int revIndex = store.size()-1;
        for(int i=0;i<store.size();i++) {
            if(store[i]!=store[revIndex--]) {
                return false;
            }
        }
        return true;
    }
};