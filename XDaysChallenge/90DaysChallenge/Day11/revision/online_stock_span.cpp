// https://leetcode.com/problems/online-stock-span

/**
 * Pattern - find continuous last n item small or equal - monotonic stack
 * understanding what to keep in .second here....
*/
class StockSpanner {
public:

    stack<pair<int, int>> store;

    StockSpanner() {
    }

    int restructureStore() {
        pair<int,int> topItem = store.top();
        store.pop();
        while(!store.empty() && store.top().first<=topItem.first) {
            pair<int, int> restTopItem = store.top();
            topItem.second = topItem.second + restTopItem.second;
            store.pop();
        }
        store.push(topItem);
        return topItem.second;
    }
    
    int next(int price) {
        store.push({price, 1});
        return restructureStore();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */