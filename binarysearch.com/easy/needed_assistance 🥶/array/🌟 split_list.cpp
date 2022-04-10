// https://binarysearch.com/problems/Split-List

/**
 * LOGIC: On first item itself consider the left array started
 * (1) Now keep moving forward and move border if num is less than or equal to
 * 
 * Q) What happens if greater number is seen?
 * A) Stop moving border as maybe right side started (keep record of this max)
 * - Now keep moving and keep saving the max value(X)
 * Q) What if we get small value than max of left side array?
 * A) Move border there & now the maxValue(X) current saved is the max value of this ride side
 * 
 * - Now keep moving and see if next values are less than max Value (X) then do the (1) again
 * 
 * COMPLEXITY: O(N)
 */
bool solve(vector<int>& nums) {
    int index=1, border=0;
    int currMax=nums[0], newMax=INT_MIN;
    bool isRightStarted=false;
    while(index<nums.size()) {
        if(!isRightStarted && nums[index]<=currMax) border=index;
        else {
            if(nums[index]<=currMax) {
                border=index;
                currMax=newMax;
                isRightStarted=false;
            } else {
                isRightStarted=true;
                newMax=nums[index]>newMax?nums[index]:newMax;
            }
        }
        index++;
    }
    return !(border==nums.size()-1);
}