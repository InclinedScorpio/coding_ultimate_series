// https://leetcode.com/problems/3sum/

/**
 * Problem requires understanding of hashing.
 * If it's sorted, 2 pointer can solve finding 2 numbers,
 * only if it's not sorted, we can use hashing to solve it.
 * 
 * O*n^2 solution
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        // nlogn------ 
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-2;i++) {
            int firstVal = nums[i];
            unordered_map<int, int> store;
            for(int j=i+1; j<nums.size();j++) {
                if(store.find(-firstVal - nums[j])!=store.end()) {
                    result.push_back({nums[i], nums[j], (-firstVal - nums[j])});
                    store[nums[j]]=j;
                    while(j!=nums.size()-1 && j<nums.size() && nums[j]==nums[j+1]) {
                        j++;
                    }
                    continue;
                }// seen it before, skip
                store[nums[j]]=j;
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1]) {
                i++;
            }
        }
        return result;   
    }
};