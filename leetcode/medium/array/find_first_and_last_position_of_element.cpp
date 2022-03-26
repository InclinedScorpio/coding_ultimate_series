// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/**
 * LOGIC:
 * - [ 2, 3, 4, 5, 5, 5, 5, 6, 7, 8]
 * - 1) We can find starting (arr[i]==target && arr[i-1]!=target) using BS
 * - 2) We can find ending (arr[i]==target && arr[i+1]!=target) using BS
 * - Check that case when start or end is target or else i-1 or i+1 will throw error
 * 
 * COMPLEXITY: O(logN)
 * 
 */ 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        int leftResult=-1, rightResult=-1;
        int left=0, right=nums.size()-1;
        
        // if starting from target, do it else mid-1 in while loop will throw error
        if(nums[0]==target) {
            leftResult=0;
        }
        if(leftResult==-1) {
            while(left<=right) {
                int mid = (left+right)/2;
                if(nums[mid]==target && nums[mid-1]!=target) {
                    leftResult = mid;
                    break;
                }
                if(nums[mid]>=target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        
        // again run BS to search for ending
        left = 0; 
        right = nums.size()-1;
        
        // if ending is target, do it else mid+1 in while loop will throw error
        if(nums[nums.size()-1]==target) {
            rightResult=nums.size()-1;
        }

        if(rightResult==-1) {
            while(left<=right) {
                int mid = (left+right)/2;
                if(nums[mid]==target && nums[mid+1]!=target) {
                    rightResult = mid;
                    break;
                }
                if(nums[mid]>target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return {leftResult, rightResult};
    }
};