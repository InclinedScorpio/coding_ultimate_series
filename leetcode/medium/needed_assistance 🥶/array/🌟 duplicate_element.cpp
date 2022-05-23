// https://leetcode.com/problems/find-the-duplicate-number/
/**
 * QUESTION: Find Duplicate number
 * 
 * LOGIC: We can do using
 * - Hashing
 * - Index sorting, try placing num to correct poss till you find it's already there (duplicate)
 * 
 * BUT, required is without using any extra space or altering given array
 * - So use Floyd Algo
 * - Logic is similar to 'Linked List Cycle II' problem
 * - Here the nums are the pointer to next index, so we can implement it similar to linked list
 * 
 * 1) First find where the slow/fast pointer meet ( will meet surely as cycle will be formed/ as dupplicate is there for sure)
 * 2) Now keep moving slow and newSlow(from head) till they meet
 * 
 * - This is start of cycle! So start of cycle is the duplicate element !!
 * HOW? because two different nodes are pointing to it, that means array are having that value at two places
 *
 * “ As we will point to other nodes based on value kept in index, hence if there are two places pointing to a node that clearly means array has that duplicate“
 * 
 */ 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;
        slow=nums[slow];
        fast=nums[nums[fast]];
        while(slow!=fast) {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=0;
        while(nums[slow]!=nums[fast]) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
    }
};