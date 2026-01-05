// https://leetcode.com/problems/daily-temperatures/

/**
 * 
 * LOGIC
 * This is a clear monotonic stack problem
 * - Whenever you see next greater, smaller, think of monotonic stack
 * O(n) solution
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> store;
        vector<int> result(temperatures.size(), 0);
        for(int i=temperatures.size()-1;i>=0;i--) {
            int currentTemp = temperatures[i];
            
            while(!store.empty() && store.top().first<=currentTemp) {
                store.pop();
            }

            result[i] = store.empty() ? 0 : store.top().second - i;
            store.push({temperatures[i], i});
        }

        return result;
    }
};