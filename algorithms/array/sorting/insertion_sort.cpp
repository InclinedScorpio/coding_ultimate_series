#include<iostream>
using namespace std;

/**
 * @INSERTION_SORT
 * 1st element sorted, so <-- sorted 1 &---> unsorted (2...3..4...)
 * 
 * LOGIC:
 * - Suppose at a point while running the algo, 3 items are already sorted
 * - Save 4th no. 
 * - Compare 3rd with 4rth, if 3rd is greater, shift 3 forward
 * - Again, check with 2nd, if 2nd is greater, shif 2 forward
 * - Oh, 1 is not greater, put 4th saved no. to 1st position
 * - Now, until 4 everything is sorted!
 * 
 * @COMPLEXITY:
 * O(N^2)
 * 
 */ 
int* sort(int arr[], int size) {
    for(int i=1;i<size;i++) {
        int unSorted=i-1;
        int temp=arr[i];
        while(unSorted>=0 && arr[unSorted]>temp) {
            arr[unSorted+1]=arr[unSorted];
            unSorted--;
        }
        arr[unSorted+1] = temp;
    }
    return arr;
}

int main() {

    int arrMy[] = {7, 41, 49, 15, 13, 43, 47, 5, 14, 19, 35, 31, 48};
    int *arr = sort(arrMy, sizeof(arrMy)/sizeof(arrMy[0]));

    for(int i=0;i<(sizeof(arrMy)/sizeof(arrMy[0]));i++) {
        cout<<arr[i]<<" ";
    }
}