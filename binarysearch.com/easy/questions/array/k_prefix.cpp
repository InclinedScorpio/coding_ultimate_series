// https://binarysearch.com/problems/K-Prefix

int solve(vector<int>& nums, int k) {
    int currSum=0;
    for(int i=0;i<nums.size();i++) {
        currSum += nums[i];
        nums[i] = currSum;
    }

    for(int i=nums.size()-1;i>=0;i--)
        if(nums[i]<=k) return i;

    return -1;
}
