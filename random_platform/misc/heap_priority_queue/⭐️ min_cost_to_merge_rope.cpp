/**
 * QUESTION: Min cost to merge all ropes we need to find
 * - After merging whatever the cost occurs that we need to keep adding
 * - Also after adding the rope length must be included in the list again
 * - ... as we need to create a single large rope
 * 
 * LOGIC: For minimum, intuition is to merge smallest ropes first
 * - And each time we need to pick two smaller ropes
 * - Also need to push the new length to the list
 * 
 * - HENCE, CLEAR CASE OF MIN HEAP - INSERTION: O(logN), DELETION: O(logN)
 * - so use priority_queue for using min heap for this
 * 
 * COMPLEXITY: O(N)- heapify + O(N(logN)^2)  :)
 * 
 * 
 * “If we had sorted everytime after deleting and pushing“
 * COMPLEXITY: O(N^2logN)  :(
 * 
 */ 
#include<iostream>
#include<queue>

using namespace std;

int minCostToMergeRope(vector<int> arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
    int cost=0;
    while(minHeap.size()>1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        cost += (first+second);
        minHeap.pop();
        minHeap.push(first+second);
    }
    return cost+minHeap.top();
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout<<minCostToMergeRope(arr);
}