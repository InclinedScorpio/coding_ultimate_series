/**
 * LOGIC: Multiple ways possible hence we do recursion (Similar to LIS !)
 * - We also see there are overalapping subproblems hence we do memoization
 * 
 * COMPLEXITY: O(N^2)
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