// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return {to_string(nums[0])};
        int left=nums[0];
        int right=nums[0];
        int insertedLeft=-1;
        vector<string> result;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1]+1) {
                right = nums[i];
                continue;
            }
            if(left==right) {
                insertedLeft = left;
                result.push_back(to_string(left));
                left=right=nums[i];
            } else {
                insertedLeft = left;
                result.push_back(to_string(left)+"->"+to_string(right));
                left=right=nums[i];
            }
        }
        if(left!=insertedLeft) {
             if(left==right) result.push_back(to_string(left));
             else result.push_back(to_string(left)+"->"+to_string(right));
        }
        return result;
    }
};