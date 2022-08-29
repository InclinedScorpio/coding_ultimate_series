// https://leetcode.com/problems/partition-equal-subset-sum/

/**
 * LOGIC: Main logic is we have a sum, and we need to find sum/2 in the array
 * - Which can be found using recursion
 * - But dp can be implemented as overlapping subproblems
 * 
 */ 
class Solution {
public:
    
    bool helper(vector<int>& nums, int amount, int ind, vector<vector<int>>& dp) {
        if(amount<0 || ind>=nums.size()) return false;
        if(amount==0) return true;
        
        if(dp[amount][ind]!=0) return false;
        
        bool dontPick = helper(nums, amount, ind+1, dp);
        if(dontPick) return true;
        
        bool pick = helper(nums, amount-nums[ind], ind+1, dp);
        if(pick) return true;
        
        dp[amount][ind]=1;
        return false;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums) sum+=i;
        if(sum%2!=0) return false;
        
        sum/=2;
        vector<vector<int>> dp(sum+1, vector<int>(nums.size(), 0));
        return helper(nums, sum, 0, dp);
    }
};