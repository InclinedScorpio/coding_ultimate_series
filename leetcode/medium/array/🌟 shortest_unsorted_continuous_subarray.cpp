// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

/**
 * LOGIC: Subarray sort to sort complete array - create graph & understand
 * Basic when understood using graph
 * 
 * Check which are the defaulters in sorted array
 * - from left check the deepest defaulter(in graph)
 * - from right check the heighest defaulter(in graph)
 * - both found? now check their right position!
 * 
 * COMPLEXITY: O(N)
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        bool foundLeftDip=false, foundRightBump=false;
        int leftDip=INT_MAX, rightBump=INT_MIN;
        for(int i=0,lastInd=nums.size()-1;i<nums.size();i++,lastInd--) {
            if(leftDip>nums[i] && i>0 && nums[i]<nums[i-1]) leftDip=nums[i];
            if(lastInd>0 && nums[lastInd-1]>rightBump  && nums[lastInd]<nums[lastInd-1])
                rightBump = nums[lastInd-1];
            if(foundLeftDip && foundRightBump) break;
        }
        if(leftDip==INT_MAX && rightBump==INT_MIN) return 0;
                
        foundLeftDip=false;foundRightBump=false;
        int leftInd, rightInd;
        for(int i=0,lastInd=nums.size()-1;i<nums.size();i++,lastInd--) {
            if(!foundLeftDip && nums[i]>leftDip) {
                foundLeftDip=true;
                leftInd=i;
            }
            if(!foundRightBump && nums[lastInd]<rightBump) {
                foundRightBump=true;
                rightInd=lastInd+1;
            }
            if(foundLeftDip && foundRightBump) break;
        }
        return rightInd-leftInd;
    }
};
