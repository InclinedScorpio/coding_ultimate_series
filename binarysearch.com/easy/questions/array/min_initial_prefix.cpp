// https://binarysearch.com/problems/Minimum-Initial-Value-for-Positive-Prefix-Sums

int solve(vector<int>& nums) {
    if(nums.size()==0) {
        return 1;
    }

    int min = INT_MAX;
    int sum=0;
    for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if(sum<min) {
            min = sum;
        }
    }
    if(min<0) return abs(min)+1;
    else return 1;
}
