//https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    //idea - store the frequency of numbers using map data structure
    map<int, int> m;
    map<int, int>::iterator it;

    for (int i = 0; i < nums.size(); i++)
    {
        it = m.find(nums[i]);
        if (it != m.end())
            it->second++;
        else
            m.insert(pair<int, int>(nums[i], 1));
    }
    map<int, int>::iterator it2;

    int dup;
    for (it2 = m.begin(); it2 != m.end(); it2++)
    {

        if (it2->second > 1)
            dup = it2->first;
    }
    return dup;
}
int main()
{

    int n;
    cin >> n;
    int temp;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    cout << findDuplicate(nums);

    return 0;
}
