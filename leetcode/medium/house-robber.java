// https://leetcode.com/problems/house-robber/

class Solution {
    public int rob(int[] nums) {
        int[] memo = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++) {
            if(i == 0)
                memo[0] = nums[0];
            else if(i == 1)
                memo[1] = Math.max(memo[0], nums[1]);
            else {
                int temp = Math.max(nums[i] + memo[i - 2], nums[i]);
                memo[i] = Math.max(temp, memo[i-1]);
            }
        }
        
        
        return memo[memo.length-1];
    }
}
