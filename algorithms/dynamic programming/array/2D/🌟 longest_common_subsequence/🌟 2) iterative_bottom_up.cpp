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

// method to print the subsequence formed using backtracking
string findStringForming(string str1, string str2, vector<vector<int>> dp) {
    int i=str1.length()-1, j=str2.length()-1;
    string str = "";
    while(i>0 && j>0) { // traverse back from end to top and see where we moved diagonally
    // diagonal movement is only done logically when char matches hence store those characters!
        if(str1[i]==str2[j]) {
            str = str1[i] + str;
            i--;j--;
        } else {
            if(dp[i-1][j]>=dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    if(i!=0) { // starting of i matches someone from j
        str = str1[i] + str;
    } else if(j!=0) { // starting of j matches someone from i
        str = str2[j] + str;
    } else { // if both i and j are 0 means 0th ind matches
        str = str1[0] + str;
    }
    return str;
}

int main() {
    string str1="ABCDUiiO";
    string str2="ZZZZABEDjjjjjUO";
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
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    cout<<dp[str1.length()-1][str2.length()-1];
    cout<<endl;
    cout<<findStringForming(str1, str2, dp);
}



