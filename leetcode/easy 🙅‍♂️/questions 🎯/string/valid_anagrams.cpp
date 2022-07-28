// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> store;
        int count=0;
        
        for(char c: s) {
            store[c]++;
            count++;
        }
        
        for(char c: t) {
            if(store.count(c) && store[c]>0) {
                store[c]--;
                count--;
            } else return false;
        }
        if(count!=0) return false;
        return true;
    }
};