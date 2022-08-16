// https://leetcode.com/problems/find-pivot-index/

/**
 * LOGIC: Simple basic problem
 * 
 */ 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i: nums) sum+=i;
        sum=sum-nums[0];
        
        int sumFromLeft=0;
        if(sum==0) return 0;
        

        for(int i=1;i<nums.size();i++) {
            sum-=nums[i];
            sumFromLeft += nums[i-1];
            if(sum==sumFromLeft) return i;
        }
        
        return -1;
    }
};