// https://binarysearch.com/problems/Longest-Alternating-Subsequence

/**
 * LOGIC: Take each index and see if it's increasing or decreasing wrt previous
 * - If increasing, that means up value must be down + 1
 * - If decreasing, that means down value must be up + 1
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
int solve(vector<int>& nums) {
    if(nums.size()==0) return 0;
    int up=1, down=1;

    for(int i=1;i<nums.size();i++) {
        if(nums[i-1]<nums[i]) {
            up = down+1;
        } else if(nums[i-1] > nums[i]) {
            down = up+1;
        }
    }
    return max(up, down);
}