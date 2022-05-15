/**
 * QUESTION: Find the longest common subsequence
 * 
 * LOGIC: We need to take both string and think of first character
 * - If both char are equal, we can move on to 2nd char of both string
 * 
 * - What if both characters are not equal?
 *  Now we can either take first ch of first string and move on to second of 2nd string
 *  Or else pick second of first and first of second string
 * 
 * - These 2 conditions are there in case char in both string doesn't match 
 * 
 * - Hence, it's clear we need to do recursion
 * - While doing recursion, while forming tree we can also see there are overlapping problem
 * - Hence we can implement DP for this problem
 * 
 */ 


#include<iostream>
#include<vector>

using namespace std;

int longestCommonSubsequence(string str1, string str2, int i, int j, vector<vector<int>>&dp) {
    if(i>=str1.length() || j>=str2.length()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j]) {
        return dp[i][j] = 1 + longestCommonSubsequence(str1, str2, i+1, j+1, dp);
    } else {
        int inc1 = longestCommonSubsequence(str1, str2, i+1, j, dp);
        int inc2 = longestCommonSubsequence(str1, str2, i, j+1, dp);
        return dp[i][j] = max(inc1, inc2);
    }
}

int main() {
    string str1="ABCD";
    string str2="ABEDG";
    vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
    cout<<longestCommonSubsequence(str1, str2, 0, 0, dp);
}
