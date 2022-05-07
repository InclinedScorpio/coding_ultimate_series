/**
 * QUESTION: Cut the rod in such a way that maximum profit is generated
 * 
 * LOGIC: Iterative Solution ( Bottom Up Approach )
 * - Idea has to be got from recursive approach (Top Down)
 * F(n) = rate[n] + max(f(rodSize-1), f(rodSize-2).....)
 * ☝️ so from here we understand that, from previous maxProfit array index we can find current max
 * 
 * - Hence we take an array of rodSize
 * - Oth is 0 as for 0 size array we have 0 profit
 * - For 1, we now need to check for each size (1-i)>=0 what's the max
 * - so on cutting 1 length it reaches 0 -> at 0 cost is 0 & cutting 1 cost is given 1
 * - Hence at 1st index -> result is -> 0 + 1 = 1
 * - Similarly we will find for 2, 3, 4, .....
 * 
 * 
 * COMPLEXITY: O(SizeOfRod*Rates)
 * - clearly nested loops running
 */ 
#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

using namespace std;

// Top Down Approach
int cutRodForMaxProfit(vector<int>& rate, int rodSize) {
    vector<int> dp(rodSize+1, 0);
    for(int i=1;i<=rodSize;i++) {
        int maxValue = INT_MIN;
        for(int j=0;j<rate.size();j++) {
            if(i-(j+1)<0) break;
            maxValue = max(maxValue, dp[i-(j+1)]+rate[j]);
        }
        if(maxValue==INT_MIN) {
            dp[i]=-1;
            continue;
        }
        dp[i]=maxValue;
    }
    return dp[rodSize];
}

int main() {
    vector<int> rate = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodSize = 8;
    cout<<cutRodForMaxProfit(rate, rodSize);
}