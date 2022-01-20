#include <iostream>
using namespace std;
void findMinMax(int a[], int n)
{
    int min = a[0];
    int max = a[0];
    cout << "min: " << min << "\n";
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > min && a[i] > max)
            max = a[i];
    }
    cout << "Max: " << max << " Min: " << min;
}
int main()
{
    int n;
    cout << "Enter the number of elements in array";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    findMinMax(a, n);
    return 0;
}