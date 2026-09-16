https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        output[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--) {
            output[i] = nums[i]*output[i+1];
        }
        
        int leftMul=1;
        for(int i=0;i<nums.size();i++) {
            if(i==nums.size()-1) {
                output[i] = leftMul;
                break;
            }
            output[i] = leftMul * output[i+1];
            leftMul= leftMul*nums[i];
        }
        return output;
    }
};


