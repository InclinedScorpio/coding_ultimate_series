// https://leetcode.com/problems/find-all-anagrams-in-a-string/

/**
 * LOGIC: Major point is we can compare the unordered map
 * - Don't need to think of optimization initially, just try to solve the damn problem -_-
 * 
 */ 
class Solution {
public:
    vector<int> findAnagrams(string p, string s) {
        queue<int> q;
        unordered_map<char, int> store;
        unordered_map<char, int> checker;
        int counter = s.length();
        if(p.length()<s.length()) return {};
        
        for(int i=0;i<s.length();i++) {
            q.push(p[i]);
            store[s[i]]++;
            checker[p[i]]++;
        }
        vector<int> result;
        
        if(checker==store) {
            result.push_back(0);
        }
        
        for(int i=s.length();i<p.length();i++) {
            char front = q.front();
            q.pop();
            checker[front]--;
            q.push(p[i]);
            checker[p[i]]++;
            
            if(checker[front]==0) checker.erase(front);
            
            if(checker==store) {
                result.push_back(i-s.length()+1);
            }
        }
        
        return result;
    }
};