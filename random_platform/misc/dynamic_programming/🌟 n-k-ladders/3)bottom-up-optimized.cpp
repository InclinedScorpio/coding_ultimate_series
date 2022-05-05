/**
 * QUESTION: Given total stairs, and number of steps/hops which can be made
 * - Find number of ways to reach the final stair from ground
 * 
 * LOGIC:
 * Bottom-up approach (iterative)
 * 
 * In 2) we already see how to find it iteratively
 * 
 * To optimize it even further
 * - We saw it had an sliding window which we can utilize to carry the sum at any position
 * - & for each further step we can simply subtract (-) => arr[i-steps-1] value
 * - Which takes the complexity to O(N) as now we don't need to go back k steps each at each N
 * 
 * COMPLEXITY: O(N)
 * 
 */ 

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
// fn = fn-1 + fn-2 + fn-3 ... + fn-k
int findTotalSteps(int ladders, int steps) {
    int arr[ladders+1];
    arr[0]=1;
    arr[1]=1;
    int currSum=2;
    for(int i=2;i<=steps;i++) {
        arr[i]=currSum;
        currSum+=arr[i];
    }
    // currSum is the sum in the window

    for(int i=steps+1;i<=ladders;i++) {
        arr[i] = (currSum - arr[i-steps-1]);
        currSum+=arr[i];
    }
    return arr[ladders];
}

int main() {
    int ladders = 4;
    int steps = 3;
    unordered_map<int, int> dp;
    cout<<findTotalSteps(ladders, steps);
}