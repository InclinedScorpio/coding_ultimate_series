/**
 * QUESTION: Find how many digits are present in longest increasing subsequence
 * 
 * LOGIC: 
 * - think of basic recursion(as multiple cases needs to be checked)
 * - thereafter as subproblems are present, we can use memoization
 * 
 * COMPLEXITY: O()
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>
#include<cstring>

using namespace std;

int helperLIS(vector<int>& arr, int* dp, int iter) {
    if(iter==arr.size()) return 0;
    if(dp[iter]!=0) return dp[iter];
    int maxValue=0;
    for(int i=iter+1;i<arr.size();i++) {
        if(arr[i]>arr[iter])
        maxValue = max(maxValue, helperLIS(arr, dp, i));
    }
    return dp[iter] = maxValue+1;
}

int longestIncreasingSubsequence(vector<int>& arr) {
    int *dp=new int[arr.size()];
    memset(dp, 0, arr.size());
    int maxValue=INT_MIN;
    for(int i=0;i<arr.size();i++) {
        maxValue = max(maxValue, helperLIS(arr, dp, i));
    }
    return maxValue;
}

int main() {
    vector<int> store = {50, 4, 10, 8, 30, 100};
    cout<<longestIncreasingSubsequence(store);
}
