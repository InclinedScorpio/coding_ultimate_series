/**
 * // Understanding kth largest
1. sorting - NlogN

2. using max heap 
  2.1 create max heap - O(N) - heapify , O(nlogn)- if insert each time
  2.2 Now, delete till k times and top one will be kth greater - O(klogN)
  - O(N) + O(klogN)
    SPACE COMPLEXITY: O(N)

3. using min heap
    3.1 just use k nodes in heap
    3.2 now create k size min heap O(k)
    3.3 now push only if item is greater than top - then only qualifies for top k ones
    3.4 if it's small don't push as it doesn't qualify for top k
    - O(k) + O(Nlogk)
    SPACE COMPLEXITY: O(k)
**/

#include<iostream>
#include<queue>
using namespace std;

int kthLargest(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> store;
    for(int i=0;i<k;i++) {
        store.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++) {
        if(arr[i]>store.top()) {
            store.pop();
            store.push(arr[i]);
        }
    }
    return store.top();
}

int main() {
    cout<<kthLargest({23,55,4,8,3,12,89,66,56,33}, 3);
}

