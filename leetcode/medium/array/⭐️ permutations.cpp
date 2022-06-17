// https://leetcode.com/problems/permutations/

/**
 * LOGIC: Swapping back into place is main logic
 * - Rest is basic recursion
 * - Try in scratch then do
 * 
 * COMPLEXITY: O(N!)
 */ 
class Solution {
public:

    void helper(vector<int> nums, int iter, vector<vector<int>>& store) {
        if(iter>=nums.size()) return;
        store.push_back(nums);
        for(int i=iter;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                swap(nums[i], nums[j]);
                helper(nums, i+1, store);
                swap(nums[i], nums[j]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> store;
        helper(nums, 0, store);
        return store;
    }
};