#include <iostream>
using namespace std;

/**
 * @BUBBLE_SORT: 
 * Bubble of 2 elements, keep swapping and shifting greater to last
 * 
 * @LOGIC:
 * - Take initial 2 items, swap the greater one forward
 * - Repeat this with each 2 item
 * - At last, last item will contain the greatest item
 * - Now repeat this again till n-1 then n-2, then n-3....
 * - At last everything will be sorted
 * 
 * @COMPLEXITY: O(N^2)
 * 
 * @visualize:
 * https://visualgo.net/en/sorting
 * 
 */ 
int* sort(int arr[], int size) {
    int lastSorted=1;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size-lastSorted;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        lastSorted++;
    }
    return arr;
}

int main() {
    int arr[] = {35, 38, 28, 10, 8, 10, 32, 48, 21, 8, 21, 20, 40, 48, 47, 47, 1};
    int* sortedArr = sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)  {
        cout<<sortedArr[i]<<" ";
    }
}