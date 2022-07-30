// https://leetcode.com/problems/word-subsets/

/**
 * LOGIC: Basic understanding of maps and logic
 * 
 * 
 */ 
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> store;
        int count=0;
        for(string s: words2) {
            unordered_map<char, int> checker;
            for(int i=0;i<s.length();i++) {
                checker[s[i]]++;
                if(store.count(s[i])) {
                    if(checker[s[i]]>store[s[i]]) {
                        store[s[i]]++;   
                        count++;
                    }
                } else {
                    store[s[i]]++;    
                    count++;
                }
            }
        }
                
        vector<string> result;
        
        for(string s: words1) {
            unordered_map<char, int> storeCopy = store;
            int countCopy = count;
            for(int i=0;i<s.length();i++) {
                if(storeCopy.count(s[i])) {
                    countCopy--;
                    if(storeCopy[s[i]]==1) {
                        storeCopy.erase(s[i]);
                    } else {
                        storeCopy[s[i]]--;
                    }
                    if(countCopy==0) break;
                }
            }
            if(countCopy==0) {
                result.push_back(s);
            }
        }
        return result;
    }
};