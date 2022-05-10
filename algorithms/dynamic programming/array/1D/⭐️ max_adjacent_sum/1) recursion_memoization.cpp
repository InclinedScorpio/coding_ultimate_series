/**
 * QUESTION: Find maximum sum where no adjacent num is choosen
 * 
 * LOGIC: 
 * - As multiple ways is possible (a tree like structure is forming)
 * - It's recursion clearly (try crude recursion initially)
 * 
 * - Also we have multiple sub problems - which indicates it's DP problem
 * - Here recursion with memoization is implemented
 * 
 * COMPLEXITY: O(2N) ~ O(N)
 * SPACE COMPLEXITY: O(N)- stack + O(N)-nums + O(N) - dp
 * 
 */   

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxAdjacentSum(vector<int>& nums, int i, vector<int>& dp) {
    if(i==nums.size()-1) return nums[i];
    if(dp[i]!=-1) return dp[i];
    
    int nextOne = maxAdjacentSum(nums, i+1, dp);
    int nextMax = INT_MIN;
    if(i<nums.size()-2) {
        for(int iter=i+2;iter<nums.size();iter++) {
            nextMax = max(nextMax, maxAdjacentSum(nums, iter, dp));
        }
    }
    return dp[i] = max(nextOne, nextMax+nums[i]);
}

int main() {
    vector<int> nums = {6, 10, 12, 7, 9, 14};
    vector<int> dp(nums.size(), -1);
    cout<<maxAdjacentSum(nums, 0, dp);
}
