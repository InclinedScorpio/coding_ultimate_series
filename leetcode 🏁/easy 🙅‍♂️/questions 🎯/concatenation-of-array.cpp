// https://leetcode.com/problems/concatenation-of-array/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> response;
        for(int i=0;i<(2*nums.size());i++) {
            if(i<nums.size()) {
                response.push_back(nums[i]);
            }else {
                response.push_back(nums[i-nums.size()]);
            }
        }
        return response;
    }
};