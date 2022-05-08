/**
 * QUESTION: Min jumps required to reach the last step of array
 * 
 * LOGIC: As from starting there can be multiple ways, we are going for recursion
 * (TOP DOWN APPROACH) 
 *
 * - From starting we are going to each node possible
 * - we will keep doing it, unless we reach the end
 * - while returning we need to do +1 to the minimum steps so steps are calculated
 * 
 * COMPLEXITY: O(N^N)
 * 
 */ 
#include<iostream>
#include<climits>

using namespace std;

int minJumpsToReachEnd(int arr[], int size, int i=0) {
    if(i>=size-1) {
        return 0;
    }
    int minValue=INT_MAX;
    for(int iter=1;iter<=arr[i];iter++) {
        minValue = min(minValue, minJumpsToReachEnd(arr, size, i+iter));
    }
    return minValue+1;
}

int main() {
    int arr[] = {3, 4, 2,10, 1, 2, 3, 7, 1, 1, 1, 2, 5};
    cout<<minJumpsToReachEnd(arr, sizeof(arr)/sizeof(arr[0]));
}
