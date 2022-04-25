/**
 * QUESTION: Sort array using HeapSort
 * LOGIC: Let's use MaxHeap to implement this as we need ascending order
 * - We will heapify the tree/array initially- this will bring biggest to the 0th index
 * - Now we can delete/swap the 0th to last and now (n-1) array exists
 * - But swapping last to 0th may have introduced non heap properties - hence heapify from 0th index once (logN)
 * 
 * - Also, intitially don't heapify the leaf nodes(N/2 to N)
 * - As we keep swapping & heapifying the swapped to front item
 * - The array keeps getting sorted from last
 * 
 * 
 * COMPLEXITY: O(NlogN)
 * logN once each item gets swapped - hence O(logN) -> mentioned in code!

 */ 


#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void heapify(vector<int>& store, int ind, int excludeLast=0) {
    int largest = store[ind];
    int largestIndex = ind;
    if(ind*2+1<(store.size()-excludeLast) && store[ind*2+1]>largest) {
        largest = store[ind*2+1];
        largestIndex=ind*2+1;
    }
    if(ind*2+2<(store.size()-excludeLast) && store[ind*2+2]>largest) {
        largest = store[ind*2+2];
        largestIndex=ind*2+2;
    }
    if(largestIndex!=ind) {
        swap(store[ind], store[largestIndex]);
        heapify(store, largestIndex, excludeLast);
    }
}

void heapifyArray(vector<int>& store) {
    for(int i=floor(store.size()/2)-1;i>=0;i--) {
        heapify(store, i);
    }
}

/// logN once each item gets swapped - hence O(logN)
void heapSort(vector<int>& store, int currLastInd) {
    if(currLastInd<=0) return;
    swap(store[0], store[currLastInd]);
    heapify(store, 0, store.size()-currLastInd); //O(logN)- equivalent to height, that to get's reducing
    heapSort(store, currLastInd-1);
}

void heapSortArray(vector<int>& store) {
    heapifyArray(store); //O(N)
    heapSort(store, store.size()-1);
}

int main() {
    vector<int> store = {10, 100, 20, 200, 50, 80, 33, 5, 1000, 2999, -1};
    heapSortArray(store);
    for(int i: store) cout<<i<<" ";
}