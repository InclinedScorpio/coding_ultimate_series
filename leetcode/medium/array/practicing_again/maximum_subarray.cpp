// https://leetcode.com/problems/maximum-subarray/

/**
 * 
 * Simple kadane algorithm to find the max sum subarray
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal=nums[0];
        int onGoingSum=0;
        for(int i=0;i<nums.size();i++) {
            int sumIncludingCurrent=onGoingSum+nums[i];
            if(sumIncludingCurrent>maxVal) {
                maxVal = sumIncludingCurrent;
            }
            
            if (sumIncludingCurrent<=0) {
                onGoingSum=0;
            } else {
                onGoingSum=sumIncludingCurrent;
            }
        }
        return maxVal;
    }
};