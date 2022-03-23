// https://binarysearch.com/problems/Strictly-Alternating-List

bool solve(vector<int>& nums) {
    if(nums.size()==1) return true;
    if(nums[1]<=nums[0]) return false;
    for(int i=0;i<nums.size()-1;i++)
        if(nums[i]==nums[i+1]) return false;
    return true;
}
