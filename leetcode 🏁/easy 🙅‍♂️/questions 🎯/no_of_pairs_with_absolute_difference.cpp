// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

/**
 * abs() for int
 * fabs() for double
 * fabsf() for float
 * 
 **/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(abs(nums[i]-nums[j])==k) {
                    sum++;
                }
            }
        }
        return sum;
    }
};