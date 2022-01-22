//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    //ensure the array is sorted
    sort(arr, arr + n);

    int diff = arr[n - 1] - arr[0];
    int max_num = arr[n - 1];
    int min_num = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - k < 0)
            continue;

        //decrease the height of towers towards the right by k and increase the heights towards the left
        min_num = min(arr[0] + k, arr[i + 1] - k);

        max_num = max(arr[i] + k, arr[n - 1] - k);

        diff = min(diff, max_num - min_num); //take min
    }

    return diff;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int diff = getMinDiff(arr, n, k);
        cout << diff;
    }
}