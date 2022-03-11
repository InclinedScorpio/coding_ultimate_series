// https://leetcode.com/problems/missing-number/

/**
 * LOGIC: Use cyclic sort
 * @CYCLIC SORT :
 * - Sorts items in O(1) - how? ?
 * - Condition: only possible when range [1, N] or [0, N] ....
 * - Just swap no. to their correct position
 * 
 * IN THIS QUESTIONS A no. is missing
 * - We will swap no to their correct position
 * - Can't swap N to correct as last index is not there - so ignore it
 * - Others will be at correct position on traversal
 * 
 * - Now just traverse, see where ( nums[i] != i )
 * - If all is fine, that means last index is not there! (coz 1 item is missing & item starts from 0)
 * 
 */ 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==nums.size()) continue;
            if(nums[i]!=i) {
                swap(nums[i], nums[nums[i]]);
                i--;
            }
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=i) return i;
        }
        return nums.size();
    }
};