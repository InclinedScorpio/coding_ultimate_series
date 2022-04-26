/**
 * QUESTIONS: Find running medians on each item insertion
 * 
 * LOGIC: Naiéve approach would be to insert each item & sort
 * - This would give high complexity of O(N^2logN)
 * 
 * Better complexity
 * - If we see closely....
 * - Median is the middle one in a sorted array
 * - We just want the max from left half
 * - & min from right half
 * - Min & max is something which heap implements very nicely
 * - Hence we are going to use Max Heap & Min Heap
 * - Max Heap will carry left side of array
 * - Min Heap will carry right side of array
 * - Make sure to either of heap doesn't carry more than difference of 1
 * 
 * - If item coming is more than median - means it should go to right side
 * - If max contain 2 and min 1 then if item is coming to max then shift top of max to min...
 * -... after that push item to max as difference shouldn't be more than 1.
 * 
 * - If items are equal, median would be a+b/2
 * - Else the top of heap which has more no. of item would be the median
 * 
 * 
 * 
 * COMPLEXITY: O(N(logN)^2)
 * 
 */ 


#include<iostream>
#include<queue>

using namespace std;

vector<float> findRunningMedians(vector<int> arr) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int currMedian=arr[0];
    maxHeap.push(arr[0]);
    vector<float> runningMedians = {(float)arr[0]};
    for(int i=1;i<arr.size();i++) {
        if(arr[i]>currMedian) {
            // means will be going to right
            if(maxHeap.size()<minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } 
            minHeap.push(arr[i]);
        } else { //means will be going to left - maxHeap
            if(maxHeap.size()>minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } 
            maxHeap.push(arr[i]);
        }
        if(maxHeap.size() > minHeap.size()) {
            runningMedians.push_back(maxHeap.top());
        } else if (maxHeap.size() < minHeap.size()) {
            runningMedians.push_back(minHeap.top());
        } else {
            runningMedians.push_back((maxHeap.top() + minHeap.top())/2.0);
        }
    }
    return runningMedians;
}

int main() {
    vector<int> arr = {10, 5, 2, 3, 0, 12, 18, 20, 22};
    vector<float> runningMedians = findRunningMedians(arr);
    for(float i: runningMedians) cout<<i<<" ";
}