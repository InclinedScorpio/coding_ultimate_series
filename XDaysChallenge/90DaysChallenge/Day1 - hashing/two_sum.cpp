// https://leetcode.com/problems/two-sum/description/

/**
 * Understanding of hashing
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store;
        for(int i=0;i<nums.size();i++) {
            if(store.find(target-nums[i])!=store.end()) {
                return {
                    store[target-nums[i]], i
                };
            }
            store[nums[i]] = i;
        }
        return {-1, -1};// won't reach here
    }
};

