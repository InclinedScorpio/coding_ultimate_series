// https://leetcode.com/problems/wiggle-subsequence/

/**
 * LOGIC: Think priorities as graph where we need to increase value of the point which is above
 * - Such that the neighbour has less value as compared
 * - Now neighbours can be 2 -> in left and in right
 * 
 * - Hence first we run and increment value running from left to right
 * - Then we run from right to left and increment value
 * - At last we see whatever was the max value at each point and sum them up
 * 
 * NOTE: Initially we need to make sure all point has atleast '1'
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    int helper(vector<int>& nums, int ind, bool isIncreasing, vector<vector<int>>& dp) {
        if(dp[ind][isIncreasing]!=-1) return dp[ind][isIncreasing];
        int maxVal=1;
        for(int i=ind+1;i<nums.size();i++) {
            if(isIncreasing) {
                if(nums[ind]<nums[i]) {
                    maxVal = max(maxVal, helper(nums, i, false, dp)+1);
                }
            } else {
                if(nums[ind]>nums[i]) {
                    maxVal = max(maxVal, helper(nums, i, true, dp)+1);
                }
            }
        }
        return dp[ind][isIncreasing] = maxVal;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int maxVal=0;
        vector<vector<int>> dp(1001, vector<int>(2, -1));
        for(int i=0;i<nums.size();i++) {
            maxVal = max(maxVal, helper(nums, i, true, dp));
            maxVal = max(maxVal, helper(nums, i, false, dp));
        }
        return maxVal;
    }
};