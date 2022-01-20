//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements of array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the Kth smaller value: ";
    int k;
    cin >> k;
    sort(a, a + n);
    cout << k << "th smallest element in array is: " << a[k - 1];
    return 0;
}