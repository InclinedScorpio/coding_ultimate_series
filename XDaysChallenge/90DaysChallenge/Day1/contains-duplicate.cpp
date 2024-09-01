// https://leetcode.com/problems/contains-duplicate/description/

/**
 * Problem requires understanding of hashing.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(int& num: nums) {
            if(store.find(num)==store.end()) {
                store.insert(num);
            } else return true;
        }
        return false;
    }
};