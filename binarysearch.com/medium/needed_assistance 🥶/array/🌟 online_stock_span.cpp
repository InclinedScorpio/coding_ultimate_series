// https://leetcode.com/problems/online-stock-span/

/**
 * LOGIC: Logic is similar to Next greater element (stack Q)
 * - Here we need to understand that consecutive small or equal...
 * - means till the first greater!
 * - So basically we need to check the distance of the first greater 
 * - Hence we can keep a stack to keep the stock height
 * - 1) If greater is received, pop the smaller ones (coz the right ones can will check current one or the greater than that)
 * - 2) If it's smaller, then just push as the right ones can be even smaller
 * 
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class StockSpanner {
public:
    vector<int> stocks;
    stack<int> st;
    StockSpanner() {
    }
    
    int next(int price) {
        stocks.push_back(price);
        while(!st.empty() && stocks[st.top()]<=price) {
            st.pop();
        }
        if(st.empty()) {
            st.push(stocks.size()-1);
            if(stocks.size()>1) return stocks.size();
            return 1;
        } else {
            int topItem = st.top();
            st.push(stocks.size()-1);            
            if(stocks[st.top()]==stocks[topItem]) return (st.top() - topItem)+1;
            return st.top() - topItem;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */