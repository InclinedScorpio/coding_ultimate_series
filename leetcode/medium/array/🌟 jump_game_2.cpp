// https://leetcode.com/problems/jump-game-ii/submissions/

/**
 * LOGIC: Point of confusion was that the left was supposed to be 0 initially
 * - while I was keeping left as nums[0] initially which is incorrect!
 * 
 * - Hence, both left and right must be 0 as that's the window exactly
 * - Later on we shift it to next window which is available!
 * 
 * COMPLEXITY: O(N)
 */ 
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int left=0;
        int right=0;
        if(nums.size()<=1) return 0;
        if(nums[0]>nums.size()) return 1;
        int maxReached=0;
        
        while(right<nums.size()-1) {
            for(int i=left;i<=right;i++) {
                maxReached = max(maxReached, i+nums[i]);
            }
            left = right+1;
            right = maxReached;
            jumps++;
        }
        return jumps;
    }
};


