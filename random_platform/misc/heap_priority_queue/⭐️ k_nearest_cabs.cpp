/**
 * QUESTION: Coordinates of cabs from origin is given....
 * - Find out the k smallest distance cabs present
 * 
 * LOGIC: When smallest/largest + k is given means - priority queue!
 * - So here we can use max heap!
 * - Initially build heap of k size
 * - Then keep removing top item to reach k smallest
 * - At last just fetch the remaining k items and return them
 * 
 * COMPLEXITY: O(NlogK) + O(KlogK)
 * 
 */ 

#include<iostream>
#include<queue>
#include<math.h>

using namespace std;


vector<int> kSmallest(vector<vector<int>> points, int k) {
    vector<int> distances;
    for(int i=0;i<points.size();i++) {
        distances.push_back(pow(points[i][0],2) + pow(points[i][1], 2));
    }

    priority_queue<int> heap;
    for(int i=0;i<k;i++) {
        heap.push(distances[i]);
    }
    for(int i=k;i<distances.size();i++) {
        if(heap.top()>distances[i]) {
            heap.pop();
            heap.push(distances[i]);
        }
    }
    vector<int> result;
    while(!heap.empty()) {
        result.push_back(heap.top());
        heap.pop();
    }
    return result;
}

int main() {
    vector<vector<int>> points = {
        {1,1},
        {2, 1},
        {3, 2},
        {0, 1},
        {2, 3}
    };
    vector<int> smallestK = kSmallest(points, 3);
    for(int i: smallestK) cout<<i<<" ";
}


