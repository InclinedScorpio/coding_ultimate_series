// https://leetcode.com/problems/group-anagrams/

/**
 * Should now hashing and how to use it to reduce O(N^2) complexity
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> store;

        vector<string> copyStrs = strs;

        // sort all of them
        for(int i=0;i<strs.size();i++) {
            sort(strs[i].begin(), strs[i].end());
        }

        vector<bool> itemPicked(strs.size(), false);
        // now compare
        vector<vector<string>> result;

        for(int i=0;i<strs.size();i++) {
            store[strs[i]].push_back(copyStrs[i]);
        }
        for(auto i = store.begin();i!=store.end();i++) {
            result.push_back(i->second);
        }
        return result;
    }
};