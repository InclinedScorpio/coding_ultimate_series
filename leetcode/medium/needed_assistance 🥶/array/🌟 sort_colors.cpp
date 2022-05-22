// https://leetcode.com/problems/sort-colors/

/**
 * LOGIC: we can easily do using O(N) by count sort
 * - Just counting number of 0, 1, 2
 * 
 * - But we are required to do it in a single pass without constant space
 * 
 * DUTCH NATIONAL FLAG ALGORITHM :
 * - Uses 3 different pointers
 * - Low, med, high
 * - Low's left always contains 0,
 * - high's right always contains 1
 * 
 * - So if med has 0, replace it with low,
 * - If med has 1, replace it with high
 * - Move ptr accordingly!
 * 
 * 
 * TIME: O(N)
 * SPACE: O(1) - only 3 pointer used, no extra space!
 */ 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        int low=0, med=0, high=nums.size()-1;
        
        while(med<=high) {
            if(nums[med]==0) {
                swap(nums[med], nums[low]);
                low++; med++; // it's sure that low wouldn't contain 1 or 0 hence 
            } else if(nums[med]==2) {
                swap(nums[med],  nums[high]);
                high--; // as high cn contain 0 as well do don't increment med
            } else {
                med++; // it's 1 so just increment med
            }
        }
    }
};