/**
 * QUESTION: Find maximum sum where no adjacent num is choosen
 * 
 * LOGIC: 
 * - As we already implemented recursion with memoization
 * - Exact same thing we can do in recursion if we see closely
 * - The F(N-1) calls are nothing but picking data from dp array
 * - Hence we can think that top down in terms of bottom up approach
 * 
 * COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(N) - dp
 * - Can we have a better space complexity? Maybe O(1) ?
 * 
 */   
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {
    vector<int> nums = {6, 10, 12, 7, 9, 14};
    vector<int> dp(nums.size());
    dp[nums.size()-1] = nums[nums.size()-1];
    dp[nums.size()-2] = nums[nums.size()-2];
    int currMax = nums[nums.size()-1];
    for(int i=nums.size()-3;i>=0;i--) {
        int left = dp[i+1];
        int right = currMax + nums[i];
        dp[i] = max(left, right);
        if(dp[i+1]>currMax) currMax = dp[i+1];
    }
    cout<<dp[0];
}