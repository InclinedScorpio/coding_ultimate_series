// https://leetcode.com/problems/4sum/

/**
 * LOGIC: Similar to 3 Sum
 * - Iterate 2 iteratorss i,j
 * - And use 2 pointer approach for rest of items
 * 
 */ 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        
        for(int i=0;i<nums.size()-3;i++) {
            for(int j=i+1;j<nums.size()-2;j++) {
                int left = j+1;
                int right = nums.size()-1;
                
                while(left<right) {
                    long long int currSum = (long)nums[i]+(long)nums[j]+(long)nums[left]+(long)nums[right];
                    if(currSum==target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        bool inc = true;
                        bool enteredLeft = true;
                        while(left<right && nums[left]==nums[left+1]){
                            left++;
                            inc=false;
                            enteredLeft=false;
                        };
                        left++;
                    } else {
                        if(currSum>target) {
                            right--;
                        } else {
                            left++;
                        }
                    }
                }
                while(j+1<nums.size() && nums[j]==nums[j+1])j++;
            }
            while(i+1<nums.size() && nums[i]==nums[i+1])i++;
        }
        return result;
    }
};
