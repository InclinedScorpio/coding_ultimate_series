// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // a + b = c
        // a = c - b
        unordered_map<int, int> store;
        for(int i=0;i<nums.size();i++) {
            if(store.find(target - nums[i])!=store.end()) {
                return {store[target-nums[i]], i};
            }
            store[nums[i]] = i;
        }
        return {0,0};
    }
};