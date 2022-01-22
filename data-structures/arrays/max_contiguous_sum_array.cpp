//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
//Kadane's Algorithm used
#include <iostream>
using namespace std;
int maxSumArray(int a[], int n)
{
    //idea - if the total sum of a subarray is negative then drop that subarray
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum > maxSum)
            maxSum = currSum;
        //drop the negtave sum subarray
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int max_Sum = maxSumArray(a, n);
    cout << max_Sum;

    return 0;
}