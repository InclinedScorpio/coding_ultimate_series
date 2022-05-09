/**
 * 
 * NOTE: Q can be done differently as well (taking index from N and then coming all the back to 0)
 * (here from 0 to N is done)
 * 
 * 
 * QUESTION: Height of pole are given
 * - Frog can jump to next or next of next only
 * - The price he pays for jump is difference in height
 * - Find the minimum price he needs to pay to reach end
 * 
 * 
 * LOGIC: As multiple ways are possible - this is clear case of recursion
 * - Hence we try to make a tree diagram of how to approach it
 * - Thinks in terms of index
 * 
 * 🚫 BLUNDER: Do not try to do sum at each step and pass on to next stack
 * - This will result in different sub problems rather than similar
 * 
 * LOGIC AGAIN: Think in terms of index always
 * F(N) = min( F(N-1) + height[i]-height[i-1], F(N-2) + height[i] - height[i-2])
 * 
 * COMPLEXITY: O(N*2) ~ O(N)
 * - Each step we are calling -1, -2, even tho it's memoized
 *
 */ 

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

using namespace std;

int findMinimumJump(vector<int> heights, vector<int>& dp, int i=0) {
    if(i==heights.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int left, right=INT_MAX;
    left = findMinimumJump(heights, dp, i+1) + abs(heights[i] - heights[i+1]);
    if(i < heights.size()-2)
        right = findMinimumJump(heights, dp, i+2) + abs(heights[i] - heights[i+2]);
    
    return dp[i] = min(left, right);
}

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    vector<int> dp(heights.size(), -1);
    cout<<findMinimumJump(heights, dp);
}