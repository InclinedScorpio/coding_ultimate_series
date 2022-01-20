#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = 0;
    int y = 0;
    int pos[n];
    int neg[n];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 || a[i] == 0)
        {
            pos[x] = a[i];
            cout << "a[i]: " << pos[x] << "x:" << x << "\n";
            x++;
        }
        if (a[i] < 0)
        {
            neg[y] = a[i];
            cout << "a[i]: " << neg[y] << "y:" << y << "\n";
            y++;
        }
    }
    if (y > 0)
        for (int i = 0; i < y; i++)
            cout << neg[i] << " ";
    if (x > 0)
        for (int i = 0; i < x; i++)
            cout << pos[i] << " ";

    return 0;
}