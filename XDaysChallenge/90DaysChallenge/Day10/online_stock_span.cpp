// https://leetcode.com/problems/online-stock-span/?envType=study-plan-v2&envId=leetcode-75

/**
 * 
 * Problems asks continuous last n items small or equal
 * Above is a hint to use monotonic stack
*/
stack<pair<int, int>> store;
class StockSpanner {
public:
    StockSpanner() {
        store = {};
    }
    
    int next(int price) {
        int num = 1;
        while(!store.empty() && store.top().first <= price) {
            pair<int, int> ss = store.top();
            num = ss.second + num;
            store.pop();
        }
        store.push({price, num});
        return store.top().second;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */