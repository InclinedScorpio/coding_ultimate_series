// https://leetcode.com/problems/sort-colors/

/**
 * LOGIC: BASIC,  there are minimum items-0,1,2 to sort
 * - Just keep counter for all of them and replace 
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0, white=0, blue=0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0)red++;
            else if(nums[i]==1)white++;
            else blue++;
        }
        
        int index=0;
        while(red--) {
            nums[index++]=0;
        }
        while(white--) {
            nums[index++]=1;
        }
        while(blue--) {
            nums[index++]=2;
        }
    }
};