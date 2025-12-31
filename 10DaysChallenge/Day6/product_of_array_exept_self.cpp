// https://leetcode.com/problems/product-of-array-except-self/

/**
 * 
 * Problem is a classic prefix and suffix product problem.
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        int leftMul=1, rightMul=1;
        for(int i=0,j=nums.size()-1;i<nums.size();i++,j--){
            if(i!=0) {
                leftMul*=nums[i-1];               
                left[i] = leftMul;
            }

            if(j!=nums.size()-1) {
                rightMul*=nums[j+1];
                right[j] = rightMul;
            }
        }

        vector<int> result;
        for(int i=0;i<nums.size();i++) {
            result.push_back(left[i]*right[i]);
        }
        return result;
    }
};