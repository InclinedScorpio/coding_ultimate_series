// https://leetcode.com/problems/subsets-ii

/**
 * LOGIC: Sorting + recursion is the major part here
 * - We can skip the already taken part (use scratch!!)
 * - Rest basic remains same for subset - 2^n
 * - We can make 2 recursive calls where in first part we include, and in second we don't
 * 
 * 
 * COMPLEXITY: O(2^N)
 * 
 */ 
class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, int i, vector<int> store) {
        if(i==nums.size()) {
            result.push_back(store);
            return;
        } 
        
        vector<int> save = store;
        store.push_back(nums[i]);
        helper(nums, i+1, store);
        
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        helper(nums, i+1, save);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0, {});
        return result;
    }
};