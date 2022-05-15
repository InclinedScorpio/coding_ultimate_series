/**
 * QUESTION: Find the longest common subsequence
 * 
 * LOGIC: iterative way can be derived from recursion with memoization
 * - so basically we need to pick max of (top) or (left + 1)
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int main() {
    string str1="ABCDXY";
    string str2="ABEDGXY";
    vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
    for(int i=0;i<str2.length();i++) {
        if(str1[0]==str2[i]) {
            dp[0][i]=1;
        }
        if(i>0 && dp[0][i-1]>dp[0][i]) {
            dp[0][i] = dp[0][i-1];
        }
    }
    for(int i=0;i<str1.length();i++) {
        if(str2[0]==str1[i]) {
            dp[i][0] = 1;
        }
        if(i>0 && dp[i-1][0]>dp[i][0]) {
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int i=1;i<str1.length();i++) {
        for(int j=1;j<str2.length();j++) {
            if(str1[i]==str2[j]) {
                if(dp[i][j-1]+1>dp[i-1][j]) {
                    dp[i][j]=dp[i][j-1]+1;
                    continue;
                }
            }
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout<<dp[str1.length()-1][str2.length()-1];
}
