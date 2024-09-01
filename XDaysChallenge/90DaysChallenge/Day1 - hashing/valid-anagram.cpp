// https://leetcode.com/problems/valid-anagram/

/**
 * Understanding of hashing
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        unordered_map<char, int> store;
        for(char& mychar: s) store[mychar]++;

        for(char& mychar: t) {
            if(store.find(mychar)==store.end()) return false;
            if(store[mychar]<=0) return false;
            store[mychar]--;
        }
        return true;


        

    }
};