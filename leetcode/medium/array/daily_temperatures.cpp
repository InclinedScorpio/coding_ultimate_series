// https://leetcode.com/problems/daily-temperatures/

/**
 * LOGIC: The question is basic usage of stack
 * 
 */ 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> store;
        store.push(temperatures.size()-1);
        
        for(int i=temperatures.size()-2;i>=0;i--) {
            while(!store.empty() && temperatures[store.top()]<=temperatures[i]) {
                store.pop();
            }
            if(store.empty()) {
                store.push(i);
                result[i] = 0;
            } else {
                result[i] = store.top() - i;
                store.push(i);
            }
        }
        return result;
    }
};