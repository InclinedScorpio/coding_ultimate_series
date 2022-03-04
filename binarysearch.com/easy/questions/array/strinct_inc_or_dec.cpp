// https://binarysearch.com/problems/Strictly-Increasing-or-Strictly-Decreasing

bool solve(vector<int>& nums) {
    if(nums.size()==1) return true;
    
    bool strInc=0;
    if(nums[0]==nums[1]) return false;
    if(nums[0]>nums[1]) {
        for(int i=1;i<nums.size()-1;i++) {
            if(nums[i]<=nums[i+1]) return false;
        }
    }else {
        for(int i=1;i<nums.size()-1;i++) {
            if(nums[i]>=nums[i+1]) return false;
        }
    }
    return true;
}