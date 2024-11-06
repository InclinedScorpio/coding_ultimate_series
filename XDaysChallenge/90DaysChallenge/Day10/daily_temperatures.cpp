// https://leetcode.com/problems/daily-temperatures/?envType=study-plan-v2&envId=leetcode-75

/**
 * 
 * Find the next warmer temperature
 *
 * Start from end putting items in stack
 * 
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> store;
        vector<int> result(temperatures.size(), 0);
        for(int i=temperatures.size()-1; i>=0;i--) {
            if(store.empty()) {
                store.push({temperatures[i], i});
            } else {
                while(!store.empty() && store.top().first<=temperatures[i]) {
                    store.pop();
                }
                if(!store.empty()) {
                    result[i] = (store.top().second - i);
                }
                store.push({temperatures[i], i});
            }
        }
        return result;
    }
};