// https://leetcode.com/problems/find-triangular-sum-of-an-array/

/**
 * LOGIC: Basic question
 * 
 */ 
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int right = nums.size()-1;
        while(right>0) {
            for(int i=0;i<right;i++)
                nums[i]=(nums[i]+nums[i+1])%10;
            right--;
        }
        return nums[0];
    }
};