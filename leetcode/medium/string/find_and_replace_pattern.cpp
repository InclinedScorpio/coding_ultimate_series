// https://leetcode.com/problems/find-and-replace-pattern/

/**
 * LOGIC: Comparatively easy question
 * - Requires knowledge of maps and sets
 * 
 */ 
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        for(string str: words) {
            unordered_map<char, char> store;
            unordered_set<char> used;
            bool toPick = true;
            for(int i=0;i<pattern.length();i++) {
                if(store.count(pattern[i])) {
                    if(str[i]!=store[pattern[i]]) {
                        toPick = false;
                        break;
                    }
                } else { // 
                    if(used.find(str[i])!=used.end()) {
                        toPick = false;
                        break;
                    }
                    store[pattern[i]] = str[i];
                    used.insert(str[i]);
                }
            }
            if(toPick) {
                result.push_back(str);
            }
        }
        return result;
    }
};