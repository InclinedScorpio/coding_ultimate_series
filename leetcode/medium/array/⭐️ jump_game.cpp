// https://leetcode.com/problems/jump-game/

/**
 * LOGIC: As multiple ways of solving are allowed, we can use recursion
 * 
 * - When applying recursion we see multiple sub problems and hence we can use DP!
 * 
 * COMPLEXITY: O(N^2)
 */ 
class Solution {
public:
    bool helper(vector<int>& nums, int ind, vector<int>& dp) {
        if(dp[ind]==2) return false;
        if(ind>=nums.size()-1 || nums[ind]+ind>=nums.size()-1) return true;
        for(int i=ind+1;i<=nums[ind]+ind;i++) {
            if(helper(nums, i, dp)) {
                return true;
            }
        }
        dp[ind] = 2;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        return helper(nums, 0, dp);
    }
};