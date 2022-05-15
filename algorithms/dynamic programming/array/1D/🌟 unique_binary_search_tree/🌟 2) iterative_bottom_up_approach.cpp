/**
 * LOGIC: Comes from recursion with memoization
 * - See what are we doing there
 * - The recurive call gets replaced with dp array here
 * 
 * - NOTE: This is faster solution than recursion with memo
 * 
 * COMPLEXITY: O(N^2)
 */ 

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n=4;
    vector<int> dp(n+1, 0);
    dp[0]=1;dp[1]=1;

    for(int i=2;i<n+1;i++) {
        int sum=0;
        for(int j=0;j<i;j++) {
            sum+=(dp[abs(0-j)]*dp[(i-j-1)]);
        }
        dp[i]=sum;
    }
    cout<<dp[n];
}
