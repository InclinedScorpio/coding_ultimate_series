// https://binarysearch.com/problems/High-Frequency

/**
 * LOGIC: Simple  yet see!
 * 
 */ 
int solve(vector<int>& nums) {
    unordered_map<int, int> store;
    int maxVal=0;
    for(int i: nums)  {
        store[i]++;
        maxVal = max(maxVal, store[i]);
    }
    return maxVal;
}