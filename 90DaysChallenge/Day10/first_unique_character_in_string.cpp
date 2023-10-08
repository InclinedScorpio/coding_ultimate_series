// https://leetcode.com/problems/first-unique-character-in-a-string/

/**
 * Question requires only understanding of hashmaps.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> store;
        for(char a: s) store[a]++;
        for(int i=0;i<s.length();i++){
            if(store[s[i]]==1) {
                return i;
            }
        }
        return -1;
    }
};