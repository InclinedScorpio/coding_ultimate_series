// https://binarysearch.com/problems/Missing-Numbers-From-1-to-N

/**
 * LOGIC: Intuition is - 1 to N is given
 * - Hence we can use “swap sort“ to bring items in place in O(N)
 * - Hence, the one which are not at correct position will be duplicate/missing
 * 
 * - Important, as we are using O(1) space!
 * 
 * COMPLEXITY: O(N)
 * 
 */ 

vector<int> solve(vector<int>& nums) {
    for(int i=0;i<nums.size();i++) {
        if(nums[i]!=(i+1)) {
            if(nums[nums[i]-1]==nums[i]) {
                continue;
            }
            swap(nums[nums[i]-1], nums[i]);
            i--;
        }
    }
    vector<int> res;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]!=i+1) res.push_back(i+1);
    }
    return res;
}