/**
 * LOGIC: Intuition comes from recursion
 * - Here we are required to keep track of both smallest and largest number
 * 
 * - Each index can either participate to be in lowest or highest streak
 * - ... or can start their own streak if they are bigger/smaller than current ones to start their own streak
 * 
 * - Problem similar to burglar problem where we kept 2 states at each index
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(1)
 * 
 */ 


struct Res {
    int localMax;
    int localMin;
    int globalMax;
};

class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        
        int localMax=1;
        int localMin=1;
        int globalMax=INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--) {
            if(nums[i]==0) {
                if(globalMax<0) {
                    globalMax=0;    
                }
                localMin=1;
                localMax=1;
                continue;
            }
            
            int first = localMax * nums[i];
            int second = localMin * nums[i];
            
            int currMax = max(first, max(second, nums[i]));
            int currMin = min(first, min(second, nums[i]));
            int currGlobalMax = globalMax;
            
            if(currMax>globalMax) {
                currGlobalMax = currMax;
            }
            
            localMax = currMax;
            localMin = currMin;
            globalMax = currGlobalMax;
        }
        return globalMax;
    }
};















