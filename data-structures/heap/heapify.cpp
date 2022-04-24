#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
/**
 * QUESTION: Heapify the given tree (-> heapify means recursively create heap DS)
 * 
 * LOGIC: 
 * O(NlogN)- this is simple - just use the insert to keep inserting item
 * 
 * O(N)- the leaf nodes are already following heap, we will start checking with the ones which are parent from bottom
 * - floor(N/2) TO N are the leaf nodes always
 * - Hence we can start doing from N/2
 * - We will check and replace if parent is smaller than any child
 * - And after swapping will make sure, the swapped one is recusively checked again as it could have resulted in...
 * ...loss of Heap property in that subtree
 * 
 * COMPLEXITY: O(N)
 */ 

void heapify(vector<int>& arr, int i) {
    int largest=arr[i];
    int largestIndex=i;
    if(2*i+1<arr.size() && arr[2*i+1] > largest) {
        largest = arr[2*i+1];
        largestIndex=2*i+1;
    }
    if(2*i+2<arr.size() && arr[2*i+2] > largest) {
        largest = arr[2*i+1];
        largestIndex=2*i+2;
    }
    if(largestIndex!=i) {
        swap(arr[i], arr[largestIndex]);
        heapify(arr, largestIndex);
    }
}

/// create max heap in O(N)
void heapifyArr(vector<int>& arr) {
    for(int i=floor(arr.size()/2)-1;i>=0;i--) {
        heapify(arr, i);
    }
}

int main() {
    vector<int> res = {10, 30, 50, 20, 35, 15};
    heapifyArr(res);
    for(int i: res) {
        cout<<i<<" ";
    }
}