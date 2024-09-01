// https://leetcode.com/problems/maximum-subarray/

/**
 * Question requires only understanding of when to pick a number and when to reset the sum (Kadanes Algorithm)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int r=0, maxSeen=nums[0], sum=0;
        while(r<nums.size()) {
                sum+=nums[r];
                if(sum<nums[r] || sum<0) sum=nums[r];
                maxSeen = max(sum, maxSeen);
                r++;
        }
        return maxSeen;
    }
};