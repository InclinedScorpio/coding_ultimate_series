// https://binarysearch.com/problems/Largest-Sublist-Sum


/**
 * LOGIC: Keep a currSum and reset to 0 if it sum goes below 0
 * - Keep a largest Sum seen till as well and update when required
 * - For negatives (all nums negative), separately check which is minimum
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
int solve(vector<int>& nums) {
    int currSum=0, largestSum=INT_MIN;
    for(int i=0;i<nums.size();i++) {
        if(currSum+nums[i]>=0) {
            currSum+=nums[i];
            if(currSum>largestSum) largestSum = currSum;
        } else {
            currSum=0;
        }
    }
    if(largestSum==INT_MIN) {
        return *max_element(nums.begin(), nums.end());
    }
    return largestSum;
}