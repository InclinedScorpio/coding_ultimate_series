// https://leetcode.com/problems/search-in-rotated-sorted-array/

/**
 * LOGIC:
 * Idea is to first check the point which is shifted!
 * - This can be done using Binary Search - O(logN)
 * - Just keep checking indexes based on 0th index
 * - And keep checking if you need to check left side or right side of curr index
 * - Also make sure to check if that index is the shifted index
 * - Once you find it.....
 * 
 * - Not check if num must lie in 2nd part or 1st part (just if else game)
 * - Now implement binary search in that part - O(logN)
 * 
 * COMPLEXITY: O(logN)
 * 
 */ 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // intilize pointers for performing binary search
        int left=0, right = nums.size()-1;
        
        // if array is shifted!
        if(nums[left]>nums[right]) {
            int leftSaved = nums[left];
            // binary search to find shifted point
            while(left<=right) {
                int mid = (left + right)/2;
                if(nums[mid] >= leftSaved) { // num is right side
                    left = mid+1;
                } else {
                    if(nums[mid]<nums[mid-1]) {
                        left=mid;
                        break;
                    }
                    right=mid-1;
                }
            }
        }
        
        // adjust left, right
        right = nums.size()-1;
        if(left!=0 && target > nums[right]) {
             right=left-1;
             left=0;
        } else right=nums.size()-1;
        
        // normal binary search
        while(left<=right) {
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) {
                right=mid-1;
            }else {
                left=mid+1;
            }
        }
        
        // no solution
        return -1;
    }
};