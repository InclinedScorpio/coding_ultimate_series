//https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void nextPermutation(vector<int> &v)
{
    next_permutation(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    nextPermutation(v);
    return 0;
}