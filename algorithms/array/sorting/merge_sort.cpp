#include<iostream>
#include<vector>

using namespace std;

/**
 * @MERGE_SORT:
 * Merge sort works on Divide and Conquer
 * 
 * LOGIC:
 * Basic, works on 2 pointers approach (2 sorted Arrays) - merge them to result a single sorted array
 * - Divide the array from half, and keep dividing till a single item is left
 * - Now merge the left and the right part by 2 ptr approach
 * 
 * COMPLEXITY: Dividing from middle - O(LogN) 2 pointer operation - O(N) on each step
 * Total: O(NLogN)
 * 
 */
void merge(int *arr, int i, int mid, int n) {
    int left=i, right=mid+1;
    vector<int> store;

    while(left<=mid && right<=n) {
        if(arr[left]<arr[right]) store.push_back(arr[left++]);
        else store.push_back(arr[right++]);
    }

    while(left<=mid) store.push_back(arr[left++]);
    while(right<=n) store.push_back(arr[right++]);
    int index=0;
    for(int iter=i;iter<=n;iter++) {
        arr[iter] = store[index++];
    }
}

void mergeSort(int *arr, int i, int n) {
    if(!(i<n)) {
        return;
    }
    int mid = (i+n)/2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, n);
    merge(arr, i, mid, n);
}

int main() {
    int arr[] = {18, 40, 16, 7, 23, 5, 9, 42, 42, 10, 20};
    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        cout<<arr[i]<<" ";
    }
}