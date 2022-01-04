// https://leetcode.com/problems/maximum-subarray/

/**
 * LOGIC: 
 * 1. Keep a check on current Maximim sum you have encountered
 *
 * 2. 
 * Keep a currentMax which will sum up the max value continuous
 * And if it encounters negative - turn it 0 as there is no use of having those values
 * 
 */ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMaxSum = nums[0];
        int currMax = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(currMax + nums[i] > currMaxSum && currMax + nums[i] > nums[i]) {
                currMaxSum = currMax + nums[i];
                currMax = currMax + nums[i];
            }else if(nums[i] > currMaxSum) {
              currMaxSum = nums[i];
              currMax = nums[i];  
            } else if (currMax  + nums[i] < 0) {
                currMax = 0;
            } else {
                currMax = currMax + nums[i];
            }
        }
        return currMaxSum;
    }
};