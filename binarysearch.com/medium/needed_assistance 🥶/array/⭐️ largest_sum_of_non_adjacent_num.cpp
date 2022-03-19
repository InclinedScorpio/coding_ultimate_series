// https://binarysearch.com/problems/Largest-Sum-of-Non-Adjacent-Numbers

/**
 * LOGIC: Just keep record of 2 things: 
 * 1. Including current num with previous max
 * 2. What's the max num as of now - check prev 2 values
 * 
 * What's the use of 2. point?
 * - It will help next num to use it to form next bigger num
 * - It won't have to care about which one of prev it has to include
 * - As DP already would have that info
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
int solve(vector<int>& nums) {
    pair<int, int> prevNum = {0,0};
    for(int i=0;i<nums.size();i++) {
        pair<int, int> currNum;
        if(nums[i]+prevNum.second>=prevNum.second) {
            currNum.first=nums[i]+prevNum.second;
            currNum.second=max(prevNum.first, prevNum.second);
            prevNum = currNum;
        } else {
            prevNum.second = max(prevNum.first, prevNum.second);
        }
    }
    return max(prevNum.first, prevNum.second);
}