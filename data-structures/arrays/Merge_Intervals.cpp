//https://leetcode.com/problems/merge-intervals/
//idea- if overlapping found then take the max element from the ending point and merge with the current interval
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > merge(vector<vector<int> > &intervals)
{
    vector<vector<int> > result;
    if (intervals.size() == 0)
        return result;
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);
    int j = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (result[j][1] >= intervals[i][0]) //compare the max elements of the consecutive intervals
            result[j][1] = max(result[j][1], intervals[i][1]);
        else
        {
            j++;
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main()
{
    int n1;
    cout << "Enter the number of pairs to be entered\n";
    cin >> n1;
    vector<vector<int> > intervals;
    vector<int> v1;
    cout << "Enter the 2d vector\n";
    int temp1, temp2;

    for (int i = 0; i < n1; i++)
    {

        cin >> temp1 >> temp2;
        v1.push_back(temp1);
        v1.push_back(temp2);
        intervals.push_back(v1);
        v1.clear();
    }

    vector<vector<int> > v2;
    v2 = merge(intervals);
    cout << "\nIntervals2\n";
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            cout << v2[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}