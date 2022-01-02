// https://leetcode.com/problems/search-insert-position/


/**
 * Binary Search knowledge required to solve it in O(log N)
 * 
 */ 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start=0, end=nums.size()-1, mid;
        
        while(start<=end) {

            mid = (start+end)/2; 

            if(nums[mid]>target) {
                end = mid - 1;
            } else if(nums[mid]==target) {
                break;
            }else {
                start = mid + 1;
            }
        }
        
        if(nums[mid] >= target) {
            return mid;
        }else {
            
            return mid+1;
        }
        
    }
};