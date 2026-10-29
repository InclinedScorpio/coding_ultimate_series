// https://leetcode.com/problems/house-robber/description/

class Solution {
public:

    int helper(vector<int>& nums, int i, unordered_map<int, int>& dp) {
        if(i>=nums.size()) return 0;
        if(dp.find(i)!=dp.end()) return dp[i];
        // pick
        int picked = nums[i] + this->helper(nums, i+2, dp);
        // don't pick
        int notPicked = this->helper(nums, i+1, dp);
        return dp[i]=max(picked, notPicked);
    }

    int rob(vector<int>& nums) {
        unordered_map<int, int> dp;


        return this->helper(nums, 0, dp);
        
    }
};