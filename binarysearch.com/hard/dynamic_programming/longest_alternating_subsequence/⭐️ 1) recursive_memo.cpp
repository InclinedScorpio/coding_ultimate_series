// https://binarysearch.com/problems/Longest-Alternating-Subsequence

/**
 * 
 * LOGIC: Something which comes automatic when recursion is known
 * - & how to implement memoization is known
 * 
 * - There are multiple possibilities of choosing numbers
 * - hence recursion is definitely required
 * - As there will be overlapping subproblems hence memoization is used
 * 
 */ 

int helper(vector<int>& nums, int iter, bool isIncrementing, vector<vector<int>>& dp) {
    int maxValue=0;
    if(dp[iter][isIncrementing]!=-1) return dp[iter][isIncrementing];
    for(int i=iter+1;i<nums.size();i++) {
        if(isIncrementing && (nums[i]-nums[iter]>0)) {
            maxValue = max(maxValue, helper(nums, i, false, dp));
        }
        if (!isIncrementing && (nums[i]-nums[iter]<0)) {
            maxValue = max(maxValue, helper(nums, i, true, dp));
        }
    }
    return dp[iter][isIncrementing] = maxValue+1;
}

int solve(vector<int>& nums) {
    if(nums.size()==0) return 0; // edge case
    int maxValue=0;
    vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        int currMax = max(helper(nums, 0, true, dp), helper(nums, 0, false, dp));
        maxValue = max(maxValue, currMax);
    return maxValue;
}