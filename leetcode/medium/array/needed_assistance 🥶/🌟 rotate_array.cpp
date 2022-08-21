// https://leetcode.com/problems/rotate-array/

/**
 * LOGIC: Observation is important in this question.
 * - We need to shift all items by k
 * - But after k items, all items will overflow
 * - Hence they will come to initial index
 * 
 * - This is logic building part above
 * - Hence we can simply reverse the array and bring items to back
 * - Now just reverse the required part and get the result
 * 
 */ 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};