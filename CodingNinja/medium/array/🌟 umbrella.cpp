// https://www.codingninjas.com/codestudio/problems/umbrella_1402895


/**
 * LOGIC: Problem is similar to coin change problem!
 * - Basic recursion and memoization
 * 
 */ 
#include <bits/stdc++.h> 

int helper(vector<int>& umbrella, int ind, int people, vector<vector<int>>& dp) {
    if(people==0) return 0;
    if(ind>=umbrella.size() || people<0) return -1;
    if(dp[ind][people]!=-1) return dp[ind][people];
    
    int repeat = helper(umbrella, ind, people-umbrella[ind], dp);
    int nonRepeat = helper(umbrella, ind+1, people, dp);
    if(repeat!=-1 || nonRepeat!=-1) {
        if(repeat>=0 && nonRepeat>=0) return dp[ind][people] = min(repeat+1, nonRepeat);
        if(repeat>=0) return dp[ind][people] = repeat+1;
        return dp[ind][people] = nonRepeat;
    }
    return -1;
}

int minUmbrellas(vector<int> &umbrella, int m) {
    sort(umbrella.begin(), umbrella.end(), greater<int>());
    vector<vector<int>> dp(umbrella.size()+1, vector<int>(m+1, -1));
    return helper(umbrella, 0, m, dp);
}