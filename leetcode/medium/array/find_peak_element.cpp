// https://leetcode.com/problems/find-peak-element/

/**
 * LOGIC: Basic problem
 * 
 */ 
class Solution {
public:
    int findPeakElement(vector<int> nums) {        
        nums.insert(nums.begin(), INT_MIN);
        
        for(int i=1;i<nums.size()-1;i++) {
            if(nums[i]>nums[i-1] && nums[i+1]<nums[i]) {
                return i-1;
            }
        }
        
        if(nums[1]>nums[nums.size()-1]) {
            return 0;
        } else return nums.size()-2;
    }
};