//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    //we need to modify the arrays
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            int x = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = x;
        }

        i--;
        j++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{

    int n, m, i;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (i = 0; i < n; i++)
        cin >> arr1[i];
    for (i = 0; i < m; i++)
        cin >> arr2[i];
    merge(arr1, arr2, n, m);
    for (i = 0; i < n; i++)
        cout << arr1[i] << " ";
    for (i = 0; i < m; i++)
        cout << arr2[i] << " ";

    return 0;
}