// https://leetcode.com/problems/search-in-rotated-sorted-array/

/**
 * Problem requires understanding of binary search and how to find the pivot element in the rotated array
 * 1) Find pivot first!!!!
 * 2) Then apply binary search on the left and right side of the pivot
*/
class Solution {
public:

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l = mid+1;
            else r=mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        int pivotInd = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(mid-1>=0 && mid+1<nums.size() && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) {
                pivotInd = mid;
                break;
            }
            if(nums[mid]<nums[l]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(pivotInd==-1) {
            if(nums[0]<nums[nums.size()-1]) {
                pivotInd = nums.size()-1;
            } else pivotInd = 0;
        }
        int res = binarySearch(nums, 0, pivotInd, target);
        if(res!=-1) return res;
        return binarySearch(nums, pivotInd+1, nums.size()-1, target);
    }
};