// https://leetcode.com/problems/top-k-frequent-elements/
/**
 * Problem requires understanding of hashing.
 * Also requires understanding of set and pair
 * Also requires understanding of how to use set to sort in reverse order - rbegin()
 * *i is used to get the iterator to the next element
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        for(int& num: nums) {
            store[num]++;
        }
        set<pair<int, int>> rev_store;
        for(auto i = store.begin(); i!=store.end();i++) {
            pair<int, int> toStore = {i->second, i->first};
            rev_store.insert(toStore);
        }
        vector<int> result;
        for(auto i=rev_store.rbegin();k;k--, i++) {
            pair<int, int>retrieved = *i;
            result.push_back(retrieved.second);
        }
        return result;
    }
};
