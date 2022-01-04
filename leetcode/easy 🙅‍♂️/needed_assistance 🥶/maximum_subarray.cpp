// https://leetcode.com/problems/maximum-subarray/

/**
 * LOGIC: 
 * 1. Keep a check on current Maximim sum you have encountered
 *
 * 2. 
 * Keep a currentSum which will sum up the max value continuous
 * And if it encounters negative - turn it 0 as there is no use of having those values
 * 
 * CATCH: max(currSum+nums[i], nums[i]) should be done as 'nums[i]' maybe positive and must not be skipped
 */ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMaxSum = INT_MIN;
        int currSum = 0;
        
        for(int i=0;i<nums.size();i++) {

            // use max of both otherwise nums[i] will be skipped in current iteration
            int additionToDo = max(currSum+nums[i], nums[i]);
            if(additionToDo > currMaxSum) {
                currMaxSum = additionToDo;
                currSum = additionToDo;
            }else if (additionToDo > 0) {
                currSum = additionToDo;
            } else {
                currSum = 0;
            }
        }
        return currMaxSum;
    }
};