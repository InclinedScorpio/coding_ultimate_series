// https://leetcode.com/problems/product-of-array-except-self/description

/**
 * 
 * Problem requires understanding of how to use two arrays to store left and right product of each element
 *  
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return nums;

        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);    

        int leftMul = 1;
        int rightMul = 1; 
        int indRev = nums.size()-1;
        for(int i=0;i<nums.size();i++, indRev--) {
            leftMul *=nums[i];
            rightMul *=nums[indRev];
            left[i]= leftMul;
            right[indRev] = rightMul;
        }

        vector<int> result(nums.size(), 1);
        result[0] = right[1];
        result[nums.size()-1] = left[nums.size()-2];

        for(int i=1;i<nums.size()-1;i++) {
            result[i] = left[i-1] * right[i+1];
        }

        return result;
    }
};