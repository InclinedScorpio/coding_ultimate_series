// https://binarysearch.com/problems/Remove-Duplicate-Numbers

/**
 * LOGIC: Basic, Used map for storing count
 * - And then checking and storing items as they appear
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
vector<int> solve(vector<int>& nums) {
    unordered_map<int, int> store;
    for(int i=0;i<nums.size();i++) {
        store[nums[i]]++;
    }
    vector<int> res;
    for(int i=0;i<nums.size();i++) {
        if(store.count(nums[i]) && store[nums[i]]==1) {
            res.push_back(nums[i]);
        }
    }
    return res;
}