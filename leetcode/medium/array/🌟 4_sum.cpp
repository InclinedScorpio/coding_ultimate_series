// https://leetcode.com/problems/4sum/

/**
 * LOGIC: Similar to 3 Sum
 * - Iterate 2 iteratorss i,j
 * - And use 2 pointer approach for rest of items
 * 
 * - BUT as we want non duplicate
 * - We can shift forward once a ind is done using lower_bound as we don't want to repeat things
 * - As it's sorted, make use of lower_bound & upper_bound to move the indices
 * - Even i, j can be moved using this binary search technique to save time
 * 
 * - NOTE: We don't require a map to store anything as we are moving using lower/upper bound & not repeating anything
 * 
 * COMPLEXITY: O(N^3)
 */ 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(),  nums.end());
        vector<vector<int>> result;

        for(int i=0;i<nums.size()-3;) {
            for(int j=i+1;j<nums.size()-2;) {
                int left=j+1;
                int right=nums.size()-1;
                while(left<right) {
                    long long sum = nums[i] + (long long)nums[j] + nums[left] + (long long)nums[right];
                    if(sum==target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left = upper_bound(nums.begin(), nums.end(), nums[left]) - nums.begin();
                    } else if(sum<target) {
                        left = upper_bound(nums.begin(), nums.end(), nums[left]) - nums.begin();
                    } else if(sum>target) {
                        right = lower_bound(nums.begin(), nums.end(), nums[right]) - nums.begin()-1;
                    }
                }
                
                j = upper_bound(nums.begin(), nums.end(), nums[j]) - nums.begin();
            }
            i = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
        }
        return result;
    }
};
