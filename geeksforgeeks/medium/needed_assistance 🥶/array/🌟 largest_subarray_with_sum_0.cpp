// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

/**
 * 
 * LOGIC: A1, A2, A3, A4, A5, A6, A7, A8, A9
 * - If Sum from A1-A4 is 8 and A1-A9 is 8
 * - What does that means?
 * - That means A5-A9 sum is 0!
 * - This is the logic of this question
 * 
 * - At each point we can see what's the sum and store it's index in map 
 * - Also, while travelling keep storing sum and check if same sum appeared somwhere else?
 * - If yes then just find distance till that index
 * 
 * - NOTE: If 8 sum comes store the first index of it's occurance
 * - As storing further index will reduce the subarray size (it can obviously occur further if later part results 0, then sum will be again 8)
 * 
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(N)
 * 
 */ 
class Solution{
    public:
    int maxLen(vector<int>&A, int n) {
        
        int currSum=0;
        unordered_map<int, int> sumStore;
        int maxRes=0;
        sumStore[0]=-1; // so that if fist is 0 or {-1, 1} we can say we have 0 in -1 while comparison
        
        for(int i=0;i<n;i++) {
            currSum+=A[i];
            if(sumStore.count(currSum)) {
                if(maxRes<(i - sumStore[currSum])) {
                    maxRes = i - sumStore[currSum];
                }
            } else {
                sumStore[currSum] = i;
            }
        }
        return maxRes;
    }
};