// https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        int current_sum=0;
        for(int i=0;i<nums.size();i++) {
            current_sum+=nums[i];            
            sum.push_back(current_sum);
        }
        return sum;
    }
};