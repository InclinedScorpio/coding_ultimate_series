// https://binarysearch.com/problems/Swap-Consecutive-Index-Pairs

vector<int> solve(vector<int>& nums) {
    vector<int> checker(nums.size(), 0);

    for(int i=0;i<nums.size();i++) {
        if(i+2 < nums.size() && checker[i]==0) {
            swap(nums[i], nums[i+2]);
            checker[i+2]=1;
        } 
    }
    return nums;
}