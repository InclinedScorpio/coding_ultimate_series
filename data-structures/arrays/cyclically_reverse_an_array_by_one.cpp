//https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cout << "Enter the number of elements of array: ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    reverse(a, a + n);
    reverse(a + 1, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}