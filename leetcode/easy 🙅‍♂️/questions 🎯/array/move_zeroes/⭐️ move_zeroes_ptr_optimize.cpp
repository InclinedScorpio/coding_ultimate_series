// https://leetcode.com/problems/move-zeroes/

/**
 * LOGIC: Keep a ptr-- which will check where to insert numbers...
 * - ...if a number is 0, ptr will make sure any proceeding number replaces it
 * - This will happen till last
 * - Now whatever no. of zeroes are must replace the last n(noOfZeroes) indices
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        int zeroPtr=0;
        if(nums.size()==1) { //edge case
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) {
                zeroes++;
            }else {
                nums[zeroPtr++] = nums[i];
            }
        }

        // replace zeroes at last
        for(int i=(nums.size()-1);i>=(nums.size()-zeroes);i--) {
            nums[i] = 0
        }
    }
};s
