#include<iostream>
#include<vector>

using namespace std;

/**
 * QUESTION: Delete item from Heap - Always top is deleted in heap (in mapHeap - top will be max item)
 * 
 * LOGIC: Remove first item and place the last one (as per complete binary tree)- last one in array
 * - ... to the first position and now swap it with child if required till it's placed correctly
 * 
 * COMPLEXITY: O(logN)
 *
 */ 
vector<int> deleteFromHeap(vector<int> heap) {
    heap[1] = heap[heap.size()-1];
    heap.pop_back();
    int currIndex=1;
    while((currIndex*2<heap.size() && heap[currIndex*2]>heap[currIndex]) || 
    (currIndex*2+1<heap.size() && heap[currIndex*2+1])) {
        /// atleast one of child is greater
        int index = 0;
        if(currIndex*2+1<heap.size()) {
            index = heap[currIndex*2] > heap[currIndex*2+1] ? currIndex*2 : currIndex*2+1;
        } else {
            index = currIndex*2;
        }
        if(heap[index] > heap[currIndex]) {
            swap(heap[index], heap[currIndex]);
            currIndex = index;
        }
    }
    return heap;
}

int main() {
    vector<int> heap = {-1, 50, 30, 40, 10, 5, 20, 30, 8};
    heap = deleteFromHeap(heap);
    for(int i: heap) {
        cout<<i<<" ";
    }
}