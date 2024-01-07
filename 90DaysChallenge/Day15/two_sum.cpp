// https://leetcode.com/problems/two-sum/


/**
 * Question requires understanding of unordered maps to be solved in O(n) time.
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store;
        for(int i=0;i<nums.size();i++) {
            if(store.find(target-nums[i])!=store.end()) {
                return {store[target-nums[i]], i};
            }
            store[nums[i]]=i;
        }
        return {0, 0};
    }
};