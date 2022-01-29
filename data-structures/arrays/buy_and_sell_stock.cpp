//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(int a[], int n)
{

    int maxprofit = 0;
    int minelement = a[0];
    for (int i = 1; i < n; ++i)
    {
        maxprofit = max(maxprofit, a[i] - minelement);
        minelement = min(a[i], minelement);
    }
    return maxprofit;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxProfit(a, n);
    return 0;
}