// https://binarysearch.com/problems/Wolves-of-Wall-Street

/**
 * LOGIC: Greedy
 * - Pick stock... and keep waiting for it to go max
 * - If it falls... leave current stock and pick that lower stock
 * - Why? Because profit will be more now!
 * - That's the catch
 * 
 * COMPLEXITY: O(N)
 */ 
int solve(vector<int>& prices) {
    if(prices.size()==0) return 0; // edge case

    int currStock=prices[0];
    int profit = 0;
    
    for(int i=1;i<prices.size();i++) {

        if(prices[i]>currStock) { // if curr stock price > stock bought
            if(i==prices.size()-1) {
                profit+=(prices[i]-currStock);
                break;
            }else {
                if(prices[i+1]>prices[i]) continue;
                profit+=(prices[i]-currStock);
                currStock = prices[i+1];
                i++; continue;
            }
        } 
        else {
            currStock = prices[i];
        }
    }

    return profit;
}