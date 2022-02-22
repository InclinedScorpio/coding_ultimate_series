#include<iostream>

using namespace std;

/**
 * @SELECTION_SORT
 * Most Basic Sort
 * - Just like selection on a ground done manually (looking, swapping minimum)
 * 
 * @LOGIC:
 * - Let's say current is min
 * - Now check rest and see if there is any other min
 * - If yes swap it and keep finding other min
 * - Once done, same from i+1
 * - At last, all will be sorted
 * 
 * @visualize:
 * https://visualgo.net/en/sorting
 * 
 * @COMPLEXITY: O(N^2)
 */ 
int* sort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        int min=arr[i];
        for(int j=i+1;j<size;j++) {
            if(min>arr[j]) {
                min=arr[j];
                arr[j]=arr[i];
                arr[i]= min;
            }
        }
    }
    return arr;
}

int main() {
    int arr[] = {27, 25, 14, 14, 45, 23, 4, 39, 34, 39, 11, 7, 4, 2, 21, 26, 8};
    int *sortedArr = sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        cout<<sortedArr[i]<<" ";
    }
}
