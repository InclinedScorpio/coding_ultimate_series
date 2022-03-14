#include <iostream>
#include <vector>
using namespace std;

/**
 * The part where we start Memoizing the result is what DP is
 * - Here we are storing the values for which result already is there
 * - HashMap could be used but array lookup is faster than map's, althouh both are O(1)
 * 
 */ 
int fibo(int n, vector<int>& dp) {
    if(n<=1) {
        return dp[n]=n;
    }

    if(dp[n]!=0) {
        return dp[n];
    }

    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

int fiboStarter(int n) {
    vector<int> dp(n+1, 0);
    return fibo(n, dp);
}

int main() {
    int n=2;
    cout<<fiboStarter(n);
}
