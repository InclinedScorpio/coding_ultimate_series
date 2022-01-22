// https://leetcode.com/problems/contains-duplicate/

/**
 * LOGIC: Basic
 * - Use map to store number which have occured already
 * 
 * 
 * OTHERSOLUTIONS:
 * 1) Sort and check adjacent values.
 * 2) Use set<int>(nums.begin(), nums.end()) -> if size<nums.size() means duplicate exists.
 * 
 */ 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> store;
        for(int i: nums) {
            if(store.find(i)!=store.end()) {
                return true;
            }
            store[i] = 1;
        }
        return false;
    }
};