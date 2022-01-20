//#https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    cout << "Enter the elements of array: ";
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            zeros++;
        if (a[i] == 1)
            ones++;
        if (a[i] == 2)
            twos++;
    }
    if (zeros > 0)
        for (int i = 0; i < zeros; i++)
            cout << "0 ";
    if (ones > 0)
        for (int i = 0; i < ones; i++)
            cout << "1 ";
    if (twos > 0)
        for (int i = 0; i < twos; i++)
            cout << "2 ";
    return 0;
}