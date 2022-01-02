// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0) {
            return 0;
        }
        
        int currStored = nums[0];
        int indexStored = 1;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==currStored) {
                continue;
            }
            nums[indexStored] = nums[i];
            currStored = nums[i];
            indexStored++;
        }
        
        return indexStored;
    }
};
