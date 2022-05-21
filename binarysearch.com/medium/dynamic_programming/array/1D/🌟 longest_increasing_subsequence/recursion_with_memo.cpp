// https://binarysearch.com/problems/Longest-Increasing-Subsequence

int helper(vector<int>& nums, int iter, vector<int>& dp) {
    int maxRecursiveVal=0;
    if(dp[iter]!=-1) return dp[iter];
    for(int i=iter+1;i<nums.size();i++) {
        if(nums[i]>nums[iter]) {
            maxRecursiveVal = max(maxRecursiveVal, helper(nums, i, dp));
        }
    }
    return dp[iter] = maxRecursiveVal+1;
}

int solve(vector<int>& nums) {
    int maxRes=0;
    vector<int> dp(nums.size(), -1);
    for(int i=0;i<nums.size();i++) {
        maxRes = max(maxRes, helper(nums, i, dp));
    }
    return maxRes;
}