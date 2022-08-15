// https://leetcode.com/problems/subsets/

/**
 * LOGIC: We don't need for loop here, just recursive call works here :)
 * 
 * - Basic solution only
 * 
 */ 
class Solution {
public:
    void helper(vector<int>& nums, int ind, vector<int> result, vector<vector<int>>& res) {
        if(ind==nums.size()) {
            res.push_back(result);
            return;
        }
        helper(nums, ind+1, result, res);
        result.push_back(nums[ind]);
        helper(nums, ind+1, result, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, 0, {}, result);
        return result;
    }
};
