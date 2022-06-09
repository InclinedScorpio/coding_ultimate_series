// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/**
 * LOGIC: It's asked to use O(1) space
 * - Hence we can use 2 pointers
 * - One for where to replace
 * - And one for traversing
 * - Just replace when required
 * - Use scratch to understand when to replace
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int rep = 1;
        for(int i=1;i<nums.size();i++)
            if(nums[rep-1]<nums[i]) nums[rep++] = nums[i];
        return rep;  
    }
};