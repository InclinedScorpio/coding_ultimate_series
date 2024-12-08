// https://leetcode.com/problems/daily-temperatures

/**
 * Undestand pattern - find next >  so monotonic stack
 * what to keep in .second -> index so can relate and give answer
*/
class Solution {
public:
    stack<pair<int, int>> store;

    int getDayDiff(int item, int ind) {
        pair<int, int> newItem = {item, ind};
        int toReturn = 0;
        while(!store.empty() && store.top().first<=item) {
            store.pop();
        }
        int diff=0;
        if(!store.empty())
            diff = store.top().second - ind;
        store.push(newItem);
        return diff;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        for(int i=temperatures.size()-1;i>=0;i--)
            result.push_back(getDayDiff(temperatures[i], i));
        reverse(result.begin(), result.end());
        return result;        
    }
};
