// https://leetcode.com/problems/product-of-array-except-self/description/

/**
 * Understanding of prefix sum 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int mul = 1;
        for(int i=0;i<nums.size();i++) {
            res[i] = mul;
            mul = mul * nums[i];
        }


        mul = 1;

        for(int i=nums.size()-1;i>=0;i--) {
            int saveCurr = nums[i];
            nums[i] = mul;
            mul = mul * saveCurr;
        }

        vector<int> result(nums.size(), 1);
        for(int i=0;i<nums.size();i++) {
            if(i==0) result[0] = nums[0];
            else if(i==nums.size() - 1) result[i] = res[i];
            else result[i] = nums[i] * res[i];
        }
        return result;


        
    }
};