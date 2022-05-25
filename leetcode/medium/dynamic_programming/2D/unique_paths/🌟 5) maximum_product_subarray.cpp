// https://leetcode.com/problems/maximum-product-subarray/

/**
 * 
 * LOGIC: Clearly can be seen it's a recursive problem as multiple ways are possible
 * 
 * - Things to note
 * 1) We have negative values, so keep a min value at each index so it can be changed to positive at right time (when next -ve comes)
 * 2) 0 comes - just make sure globalMax is not -ve, in that make it 0 as it would be the max then
 * 
 * At each index, we have 2 choices either take it in our localMax or localMin
 * Include it whereever required
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
    Res helper(vector<int>& nums, int i) {
        if(i==nums.size()) return {1, 1, INT_MIN};
        Res res = helper(nums, i+1);
        if(nums[i]==0) {
            if(res.globalMax<0) {
                res.globalMax=0;    
            }
            return {1, 1, res.globalMax};
        }
        
        int first = res.localMax * nums[i];
        int second = res.localMin * nums[i];
        
        int currMax = max(first, max(second, nums[i]));
        int currMin = min(first, min(second, nums[i]));
        int currGlobalMax = res.globalMax;
        
        if(currMax>res.globalMax) {
            currGlobalMax = currMax;
        }
        return {currMax, currMin, currGlobalMax};
    }
    
    int maxProduct(vector<int>& nums) {
        return helper(nums, 0).globalMax;
    }
};















