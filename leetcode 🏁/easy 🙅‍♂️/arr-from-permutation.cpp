// https://leetcode.com/problems/build-array-from-permutation/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ansVect;
        
        for(int i=0;i<nums.size();i++) {
            ansVect.push_back(nums[nums[i]]);
        }
        return ansVect;
    }
};