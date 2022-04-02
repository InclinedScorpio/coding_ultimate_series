// https://binarysearch.com/problems/Sum-of-Two-Numbers-Less-Than-Target

/**
 * LOGIC: Point to understand is to how to use 2 pointer approach
 * - After sorting, we need to keep i at 0 and j at last
 * - Now just move i forward and j backward as per condition
 * - And store the max value you get as per condition
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 
int solve(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int currMax=INT_MIN;
    int i=0, j=nums.size()-1;
    while(i<j) {
        if(nums[i]+nums[j]>=target) {
            j--;
        } else {
            currMax = max(currMax, nums[i]+nums[j]);
            i++;
        }
    }
    return currMax;
}