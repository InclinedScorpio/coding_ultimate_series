// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

/**
 * LOGIC: Question is hard, but actually basic logic
 * - We need to pick all words from the given array
 * - Hence first we can make an map of it
 * 
 * - THING TO NOTE IS : All words are same size!
 * - Hence we need to check the length from the given string when checking
 * - If the formed string exists in map then reduce conter
 * - If not exists, that means that part of string can't hold all the values
 * 
 * - Hence as soon as counter becomes 0 we get requried index
 * - Make sure the next time start from i+1
 * 
 * COMPLEXITY: O(N^2)
 */ 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int singleSize = words[0].size();
        int totalSize = words.size() * singleSize;
        unordered_map<string, int> storeOrg;
        int counterOrg=0;
        for(string s: words) storeOrg[s]++;    
        
        counterOrg = words.size();
        
        vector<int> result;
        
        for(int i=0;i<s.length()-totalSize+1;i++) {
            unordered_map<string, int> store = storeOrg;
            int counter = counterOrg;
            string str="";
            for(int j=i;j<s.length();j++) {
                str+=s[j];
                if(str.length()==singleSize && store.find(str)==store.end()) break;
                if(str.length()==singleSize) {
                    counter--;
                    store[str]--;
                    if(store[str]==0) store.erase(str);
                    
                    if(counter==0) {
                        result.push_back(j-totalSize+1);
                        break;
                    } else str="";
                }
            }   
        }
        return result;
    }
};