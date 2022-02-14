// https://binarysearch.com/problems/Largest-Gap

int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int currMax = nums[1]- nums[0];
    for(int i=1;i<nums.size();i++) if(nums[i]-nums[i-1]>currMax) currMax = nums[i]-nums[i-1];
    return currMax;
}
