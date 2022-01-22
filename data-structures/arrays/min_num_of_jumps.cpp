//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
#include <iostream>
#include <algorithm>
using namespace std;
int minJumps(int arr[], int n)
{
    if (n <= 1) // if array has no elements then return
        return 0;
    if (arr[0] == 0) // if the first element is 0 then no steps can be taken
        return -1;
    int maxRange = arr[0], step = arr[0], jump = 1, i = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1) // if reached at the end of array
            return jump;
        maxRange = max(maxRange, i + arr[i]); //take maximuim range
        step--;
        if (step == 0) // nee
        {
            jump++; //took a jump
            if (i >= maxRange)
                return -1;
            step = maxRange - i; //steps to be taken to reach Maxrange
        }
    }
    return -1;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Min Jumps" << minJumps(arr, n);
    }
    return 0;
}