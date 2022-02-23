// https://binarysearch.com/problems/Sorted-Elements

/**
 * LOGIC: Sort it and then see which places were already at correct pos
 * 
 * COMPLEXITY: O(NlogN)
 */ 
int solve(vector<int>& nums) {
    vector<int> save = nums;
    sort(nums.begin(), nums.end());
    int res=0;
    for(int i=0;i<nums.size();i++) {
        if(save[i]==nums[i]) res++;
    }
    return res;
}
