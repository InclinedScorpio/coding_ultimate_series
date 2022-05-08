/**
 * QUESTION: Min jumps required to reach the last step of array
 * 
 * LOGIC: As from starting there can be multiple ways, we are going for recursion
 * (TOP DOWN APPROACH) 
 *
 * 1) We already saw recursion in first step
 * 
 * - We saw the same number was called multiple times, hence we can memoize them
 * - Hence we use hashing to keep track of those values
 * 
 * COMPLEXITY: O(N*N)
 * 
 */ 
#include<iostream>
#include<climits>
#include<unordered_map>

using namespace std;

int minJumpsToReachEnd(int arr[], int size, int i, unordered_map<int, int>& dp) {
    if(i>=size-1) {
        return 0;
    }
    if(dp.count(i)) {
        return dp[i];
    }
    int minValue=INT_MAX;
    for(int iter=1;iter<=arr[i];iter++) {
        minValue = min(minValue, minJumpsToReachEnd(arr, size, i+iter, dp));
    }
    return dp[i]=minValue+1;
}

int main() {
    int arr[] = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
    unordered_map<int, int> dp;
    cout<<minJumpsToReachEnd(arr, sizeof(arr)/sizeof(arr[0]), 0, dp);
}
