// https://leetcode.com/problems/sum-of-subarray-ranges/

/**
 * LOGIC: Is easy, we just need to form the subarrays and calculate max and min at each step
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    
    long long subArrays(vector<int>& nums, int ind) {
        if(ind>=nums.size()) return 0;
        
        long long max=nums[ind], min=nums[ind];
        long long diff=0;
        for(int i=ind;i<nums.size();i++) {
            if(nums[i]>max) max = nums[i];
            if(nums[i]<min) min = nums[i];
            diff+=(max-min);
        }
        return diff + subArrays(nums, ind+1);
    }
    
    long long subArrayRanges(vector<int>& nums) {
        return subArrays(nums, 0);
    }
};