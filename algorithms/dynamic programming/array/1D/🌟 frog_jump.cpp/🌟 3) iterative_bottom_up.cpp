/**
 * 
 * NOTE: Q can be done differently as well (taking index from N and then coming all the back to 0)
 * (here from 0 to N is done)
 * 
 * 3) Good Q to understand recursion+memo to DP
 * 
 * - We see that
 *  F(N) = min( F(N-1) + height[i]-height[i-1], F(N-2) + height[i] - height[i-2])
 *  is implemented
 * 
 * - here F(N-1) is nothing but dp[i-1] and height[i]-height[i-1] is basic what we need to do
 * - hence this can be formed in a DP, which is done here
 * 
 * COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(N) - N space taken by DP
 * 
 * - Can Space Complexity be reduced ? 
 * - Yes!
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

using namespace std;

int findMinimumJump(vector<int> heights, vector<int>& dp, int i=0) {
    if(i==heights.size()-1) return 0;
    if(dp[i]!=0) return dp[i];
    int left, right=INT_MAX;
    left = findMinimumJump(heights, dp, i+1) + abs(heights[i] - heights[i+1]);
    if(i < heights.size()-2)
        right = findMinimumJump(heights, dp, i+2) + abs(heights[i] - heights[i+2]);

    return dp[i] = min(left, right);
}

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    vector<int> dp(heights.size(), 0);
    for(int i=heights.size()-2;i>=0;i--) {
        int left = dp[i+1] + abs(heights[i]-heights[i+1]);
        int right = INT_MAX;
        if(i<=heights.size()-3) {
            right = dp[i+2] + abs(heights[i]-heights[i+2]);
        }
        dp[i]=min(left, right);
    }
    cout<<dp[0];
}