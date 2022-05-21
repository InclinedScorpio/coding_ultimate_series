/**
 * QUESTION: Find how many digits are present in longest increasing subsequence
 * 
 * LOGIC: 
 * - In recursion we are iterating over all the items
 * - so, at each item, we are doing something...
 * - We are trying to find the subsequence starting from that number to later point
 * - Same thing we can do in iterative
 * 
 * - Last item can be taken as starting element of subsequence  | Dp[last]-> 1
 * - Now, we go back one step and check same thing, if subsequence can start from this point
 * - So at each later index from curr point if the point can become the first LIS, then max of (dp[ind]+1)
 * - ⭐️ It's most important to understand above 2 point, as it's crux of this problem...
 * 
 * COMPLEXITY: O(N*N)
 * - As at each index, we are iterating later to find...
 * - If curr index can become the start of LIS
 * 
 * Can we do better? Yes O(NlogN) is possible
 * 
 */ 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> store = {50, 4, 10, 8, 30, 100};
    vector<int> dp(store.size(), 0);
    dp[store.size()-1] = 1;
    for(int i=store.size()-2;i>=0;i--) {
        int maxValue = 1;
        for(int j=i+1;j<store.size();j++) {
            if(store[i] < store[j])
                maxValue = max(maxValue, dp[j]+1);
        }
        dp[i] = maxValue;
    } 
    cout<<*max_element(dp.begin(), dp.end());
}
