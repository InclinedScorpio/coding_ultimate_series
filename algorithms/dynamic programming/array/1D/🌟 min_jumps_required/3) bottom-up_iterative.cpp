/**
 * QUESTION: Min jumps required to reach the last step of array
 * 
 * LOGIC: As from starting there can be multiple ways, we are going for recursion
 * (BOTTOM UP APPROACH)
 * 
 * We need to go from left to right this time and don't pick already updated N
 * - We got this idea to go from left to right as in recursion as well we were going from left part and jumping till last index
 * 
 * COMPLEXITY: O(2N)
 * - when first is responsible for traversing complete 
 * - but still all of those will be traversed (to check if further need to do 1)
 * 
 */ 
#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

int minJumpsToReachEnd(int arr[], int size) {
    int *reached = new int[size+1];
    memset(reached, 0, size+1);
    int reachedTill=1;
    for(int i=0;i<size;i++) {
        int j=reachedTill;
        for(;j<=arr[i];j++) reached[i+j]=reached[i]+1;
        reachedTill=j-1;
    }
    return reached[size];
}

int main() {
    int arr[] = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
    cout<<minJumpsToReachEnd(arr, sizeof(arr)/sizeof(arr[0]));
}
