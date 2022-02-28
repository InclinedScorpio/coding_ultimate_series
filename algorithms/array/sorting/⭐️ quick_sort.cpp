#include <iostream>
#include <climits>

using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[l];
    int pivotIndex = l;
    while(l<=r) {
        while(arr[l]<=pivot) {
            l++;
        }
        while(arr[r]>pivot) {
            r--;
        }
        if(l<r) {
            swap(arr[l], arr[r]);
        }
    }
    swap(arr[pivotIndex], arr[r]);
    return r;
}

void quickSort(int arr[], int l, int r) {
    if(l>=r) {
        return;
    }
    int divider = partition(arr, l, r);
    quickSort(arr, l, divider-1);
    quickSort(arr, divider+1, r);
}

int main() {
    int arr[] = {2,10,1,300,34,34,35, 35, -1, 5,900,0,-2,91999, INT_MAX};
    quickSort(arr ,0 , (sizeof(arr)/sizeof(arr[0]))-1);
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]))-1;i++) {
        cout<<arr[i]<<" ";
    }
}