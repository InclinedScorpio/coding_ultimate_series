// https://binarysearch.com/problems/Shortest-Sublist-to-Sort

/**
 * #GoodQuestion
 * LOGIC: Just use a graph to understand that...
 * - You need to find point from left from where array is no more sorted
 * - Now from that point check the least no in the unsorted part and save it
 * 
 * - Do the same from right and find the point from where array is no more sorted
 * - Now fro that point check the highest no in unsorted part and save it
 * 
 * - Now just find where the least and the highest point belong in the array
 * - That's the subpart in the array you need to sort which will result in sorted array
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
int solve(vector<int>& nums) {

    if(nums.size()==0) return 0;

    int lowerLeft=INT_MAX;
    bool leftIncorrect=false;

    int lowerRight=INT_MIN;
    bool rightIncorrect=false;

    int invInd=nums.size()-2;
    for(int i=1;i<nums.size();i++) {
        if(nums[i]<nums[i-1]) {
            leftIncorrect=true;
        }
        if(leftIncorrect && nums[i]<lowerLeft) { 
            lowerLeft=nums[i];
        }
        if(nums[invInd]>nums[invInd+1]) {
            rightIncorrect=true;
        }
        if(rightIncorrect && nums[invInd]>lowerRight) {
            lowerRight=nums[invInd];
        }
        invInd--;
    }
    if(lowerLeft==INT_MAX) return 0;

    int leftIndex, rightIndex;
    invInd=nums.size()-1;
    bool foundLeftIndex=false, foundRightIndex=false;

    for(int i=0;i<nums.size();i++,invInd--) {
        if(!foundLeftIndex && nums[i]>lowerLeft) {
            foundLeftIndex=true;
            leftIndex=i;
        }

        if(!foundRightIndex && nums[invInd]<lowerRight) {
            foundRightIndex=true;
            rightIndex=invInd;
        }

        if(foundLeftIndex && foundRightIndex) return 
                    abs(rightIndex-leftIndex)+1;

    }
    return -1;
}
