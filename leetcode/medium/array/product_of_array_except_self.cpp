// https://leetcode.com/problems/product-of-array-except-self/

/**
 * LOGIC: As division is not allowed, just carry a left array with left division.
 * - For right multiplications, rather than having separate array just carry a variable which can do it (just to save another O(n) space)
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        int mul=1;
        for(int i: nums) {
            mul*=i;
            left.push_back(mul);
        }
        
        mul=1;
        vector<int> result(nums.size());
        for(int i=nums.size()-1;i>0;i--) {
            result[i] = left[i-1]*mul;
            mul*=nums[i];
        }
        result[0] = mul;
        return result;
    }
};