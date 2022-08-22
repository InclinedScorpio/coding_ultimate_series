// https://leetcode.com/problems/house-robber/

/**
 * LOGIC: Pick alternate houses question
 * - As multiple ways present, implemented recursion
 * - Got TLE, got idea it's DP, hence implemented DP, as overlapping subproblems
 * 
 */ 
class Solution {
public:
    
    int helper(vector<int>& nums, int ind, unordered_map<int, int>& dp) {
        // if(ind==nums.size()-1) return nums[nums.size()-1];
        if(ind>=nums.size()) return 0;
        if(dp.count(ind)) return dp[ind];
        int nextOne = helper(nums, ind+1, dp);
        int nextToNext = helper(nums, ind+2, dp);
        int nxtTonxtTonxt = helper(nums, ind+3, dp);
        return dp[ind] = max(nextOne, max(nextToNext, nxtTonxtTonxt) + nums[ind]);
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int, int> dp;
        return helper(nums, 0, dp);    
    }
};