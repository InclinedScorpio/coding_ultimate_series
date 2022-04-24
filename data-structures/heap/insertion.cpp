#include<iostream>
#include<vector>

using namespace std;

/**
 * QUESTION: Insert item in maxHeap
 * LOGIC: Firstly, we need to insert @first position as per complete binary tree
 * - Once inserted, see if root is smaller, swap if it is
 * - Do it till root is greater, hence that would be it's correct position
 * 
 * - If Tree itself is given we can form array in BFS
 * - & then do insertion and again form back tree from it
 * 
 */ 
vector<int> insertInHeap(vector<int> heap, int num) {
    /// must be inserted at last (as it's a complete binary tree)
    heap.push_back(num);
    int newNumIndex=heap.size()-1;
    while(heap[newNumIndex/2]<heap[newNumIndex] && (newNumIndex/2)!=0) {
        swap(heap[newNumIndex/2], heap[newNumIndex]);
        newNumIndex = newNumIndex/2;
    }
    return heap;
}

int main() {
    vector<int> heap = {-1, 50, 30, 40, 10, 5, 20, 30};
    heap = insertInHeap(heap, 45);
    for(int i: heap) {
        cout<<i<<" ";
    }
}