// https://binarysearch.com/problems/Pair-Sums-to-Power-of-Two

/**
 * LOGIC: O(32N)~O(N) --> major understanding
 * - Rather than thinking about removing 2 for loops
 * - Think about if we can run loop for contant time ( as upto 2^31 is only possible )
 * 
 * COMPLEXITY: O(32 N) ~ O(N)
 */ 
int solve(vector<int>& nums) {
    map<int,int> store;
    int result=0;
    for(int i=0;i<nums.size();i++) {
        for(int j=0;j<31;j++) {
            int myPow = pow(2, j);
            if(store.find(myPow-nums[i])!=store.end()) {
                result+=store[myPow-nums[i]];
            }
        }
        store[nums[i]]++;
    }
    return result;
}