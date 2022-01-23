// https://leetcode.com/problems/move-zeroes/

/**
 * LOGIC: Shift 0 to last and erase current element
 * NOTOPTIMIZED
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator itr = nums.begin();
        int size = nums.size();
        int zeroShifted = 0;
        for(int i=0;i<size-zeroShifted;i++){
            if(nums[i]==0) {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                zeroShifted++;
                i--;
            }
        }
        return;
    }
};