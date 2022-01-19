// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/**
 * LOGIC:
 * - Keep storing numbers in map
 * - For each number now keep checking if target-currentNum is already present
 * 
 */ 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> store;
        vector<int> result;
        int indexOneBased = 1;
        for(int i: numbers) {
            if(store[target-i]) {
                return {store[target-i], indexOneBased};
            }
            store[i]=indexOneBased;
            
            indexOneBased++;
        }
        return {0,0};
    }
};