// https://leetcode.com/problems/single-element-in-a-sorted-array/

/**
 * LOGIC: Completely based on observation
 * - We can obviously do XOR of all and in end will get the one single one
 * 
 * - But it's given to find in O(logN), also it's sorted - hence binary search required
 * - In binary search we can easily figure out that for even index - next will be same
 * - And for odd, previous will be same.
 * - And this will help us to reach where the num is only occuring once
 * 
 * COMPLEXITY: O(logN)
 * 
 */ 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int left=0, right=nums.size()-1;
        while(left<=right) {
            int mid = (right+left)/2;
            if(mid==0 && (nums[0]!=nums[1])) return nums[0];
            else if((mid==nums.size()-1 && (nums[nums.size()-1]!=nums[nums.size()-2]))) return nums[nums.size()-1];
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
               
            if(mid%2==0) {//even
                if(nums[mid]==nums[mid+1]) {
                    left=mid+2;
                } else {
                    right=mid-2;
                }
            } else { //odd
                if(nums[mid]==nums[mid-1]){
                    left=mid+1;
                } else {
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};