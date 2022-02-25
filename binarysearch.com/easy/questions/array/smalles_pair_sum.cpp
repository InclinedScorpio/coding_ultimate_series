// https://binarysearch.com/problems/Smallest-Pair-Sum-with-Distance-Constraint

int solve(vector<int>& nums) {

    int leastTill = nums[0];
    int leastSum = INT_MAX;
    for(int i=2;i<nums.size();i++) {
        if(nums[i]+leastTill < leastSum) {
            leastSum = nums[i]+leastTill;
        }
        if(nums[i-1]<leastTill) leastTill = nums[i-1];
    }

    return leastSum;
    
}