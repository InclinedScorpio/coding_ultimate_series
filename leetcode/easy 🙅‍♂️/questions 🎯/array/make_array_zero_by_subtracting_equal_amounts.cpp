// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

/** 
 *  Basic logic - don't keep iterating and subtracting, just use a variable
 */  
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int count=0;
        int totalSub=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0 && (nums[i] - totalSub) > 0) {
                totalSub+=(nums[i]-totalSub);
                count++;
            }
        }
        return count;
    }
};
