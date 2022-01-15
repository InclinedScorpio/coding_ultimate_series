// https://leetcode.com/problems/single-number/

// Understanding concept:
// ^ is called as XOR
// XOR will give 1 if two bits are different and 0 if both bits are similar
// So if we do 2^2 => 0 (both 2 and 2 all bits are same) & 5^2^2 -> 5 (because 2 and 2 will result in 0)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = nums[0];
        for(int i=1;i<nums.size();i++){
            value = value^nums[i];
        }
        return value;
    }
};