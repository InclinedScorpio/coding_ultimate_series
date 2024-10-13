// https://leetcode.com/problems/permutation-in-string/

/**
 * Understanding that we need to keep track of the length of the substring that we are considering
 * Permutation is nothing but a substring of length s1.length() that is present in s2
 * Using simple window we can solve this problem
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> store;
        for(char a: s1) {
            store[a]++;
        }
        int left=0, right=0, len=0;
        unordered_map<char, int> storeMatcher;
        while(right<s2.length()) {
            if(store.find(s2[right])!=store.end()) {
                storeMatcher[s2[right]]++;
                len++;
                if(store[s2[right]]<storeMatcher[s2[right]]) {
                    while(s2[left]!=s2[right]) {
                        storeMatcher[s2[left]]--;
                        left++;
                        len--;
                    }
                    storeMatcher[s2[left]]--;
                    left++;
                    len--;
                } else {
                    if(len==s1.length()) {
                        return true;
                    }
                }
            } else {
                storeMatcher.clear();
                left=right+1;
                len=0;
            }
            right++;
        }
        if(len==s1.length()) return true;
        return false;
    }
};