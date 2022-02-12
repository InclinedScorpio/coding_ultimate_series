// https://binarysearch.com/problems/Arithmetic-Sequence-Permutation

/**
 * LOGIC: Similar diff will only occur if it's sorted!
 * 
 */ 
bool solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int diff = nums[1] - nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        if(nums[i+1]-nums[i] != diff) return false;
    }
    return true;
}
