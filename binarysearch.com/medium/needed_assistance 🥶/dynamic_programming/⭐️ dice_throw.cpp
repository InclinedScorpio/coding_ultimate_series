// https://binarysearch.com/problems/Dice-Throw

/**
 * LOGIC: Only thing didn't came up was this is a DP problem
 * - Or it can be solved through recursion
 * - Hence think of basic way of solving first then advance
 * 
 */ 
long long int divBy= pow(10, 9) + 7;

int helper(int n, int faces, int total, vector<vector<int>>& dp) {
    if(total<0) return 0;
    if(total==0&&n!=0) return 0;
    if(total==0) return 1;
    
    if(dp[n][total]!=-1) return dp[n][total];
    if(n==0) return 0;

    int currResult = 0;
    for(int i=1;i<=faces;i++) {
        currResult=(currResult+((helper(n-1, faces, total-i, dp))%divBy))%divBy;
    }
    return dp[n][total] = currResult;
}

int solve(int n, int faces, int total) {
    vector<vector<int>> dp(101, vector<int>(101, -1));
    return helper(n, faces, total, dp);
}