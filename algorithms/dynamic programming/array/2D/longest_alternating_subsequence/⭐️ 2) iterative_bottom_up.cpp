// https://binarysearch.com/problems/Longest-Alternating-Subsequence

/**
 * LOGIC: comes from recursion
 * - We just converted recursion to iterative
 * - Each index carries 2 states
 * - And based on it results are calculated for every other index
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
int solve(vector<int>& nums) {
    if(nums.size()==0) return 0; // edge case

    vector<pair<int, int>> dp(nums.size());
    dp[nums.size()-1] = {1, 1};
    for(int i=nums.size()-2;i>=0;i--) {
        int maxInc=0, maxDec=0;
        for(int j=i+1;j<nums.size();j++) {
            if(nums[j]>nums[i] && dp[j].second>maxInc) {
                maxInc = dp[j].second;
            }
            if(nums[j]<nums[i] && dp[j].first>maxDec) {
                maxDec=dp[j].first;
            }
        }
        dp[i] = {maxInc+1, maxDec+1};
    }

    return max(dp[0].first, dp[0].second);
}