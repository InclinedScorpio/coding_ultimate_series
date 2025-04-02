// https://leetcode.com/problems/house-robber-ii/description/

/**
 * 
 * Variation of house robbery 1, here you need to check if first was taken or not thats all
 * firsttaken contributes to each stack result so keep it in dp! - important
 */
class Solution {
public:
    int helper(vector<int>& nums, int i, bool firstTaken, vector<vector<int>>& dp) {
        if(i>=nums.size()) return 0;
        if(dp[i][firstTaken]!=-1) return dp[i][firstTaken];

        int maxSeen=0;

        // take
        if(i==0) {
            maxSeen = helper(nums, i+2, true, dp) + nums[i];
        } else if(i==nums.size()-1) {
            if(firstTaken) {
                return 0;
            } else {
                return nums[nums.size()-1];
            }
        } else {
            maxSeen = helper(nums, i+2, firstTaken, dp) + nums[i];
        }
        // not take
        if(i==0) {
            maxSeen = max(maxSeen, helper(nums, i+1, false, dp));
        } else {
            maxSeen = max(maxSeen, helper(nums, i+1, firstTaken, dp));
        }

        return dp[i][firstTaken]=maxSeen;
    }

    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return helper(nums, 0, true, dp);
    }
};