// https://binarysearch.com/problems/Making-Change-Sequel

/**
 * LOGIC: Forgot about basic DP
 * - Here it's clearly visible that all different ways needs to be checked as anything is possible
 * - Hence we clearly need a recursion
 * - As overlapping problems may also exist hence based on ind, amount we can memoize
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
int helper(vector<int>& denominations, int ind, int amount, vector<vector<int>>& store) {
    if(amount<0 || denominations[ind]==0) return INT_MAX;
    if(amount==0) return 0;
    if(ind==denominations.size()) return INT_MAX;
    if(store[ind][amount]!=-1) return store[ind][amount];
    
    if(amount%denominations[ind] == 0) return amount/denominations[ind];
    
    int same = helper(denominations, ind, amount - denominations[ind], store);
    if(same!=INT_MAX) same++;
    int nonSame = helper(denominations, ind+1, amount, store);
    
    return store[ind][amount] = min(same, nonSame);
}

int solve(vector<int>& denominations, int amount) {
    vector<vector<int>> store(denominations.size(), vector<int>(amount+1, -1));
    sort(denominations.begin(), denominations.end(), greater<int>());
    int res = helper(denominations, 0, amount, store);
    if(res==INT_MAX) return -1;
    return res;
}