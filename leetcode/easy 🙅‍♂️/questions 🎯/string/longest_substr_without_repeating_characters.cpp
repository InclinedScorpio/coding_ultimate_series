// Problem Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <string>
#include <set>
using namespace std;
int lengthOfLongestSubstr(string str)
{
    set<char> st;
    int i = 0, j = 0, maxi = 0;
    while(i < str.length() && j < str.length())
    {
        if(st.empty() || st.find(str[j]) == st.end())
        {
            st.insert(str[j]);
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else
        {
            st.erase(str[i]);
            i++;
        }
    }
    return maxi;
}
int main()
{
    string str; cin >> str;
    cout << lengthOfLongestSubstr(str) << endl;
    return 0;
}