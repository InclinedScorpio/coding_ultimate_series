// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/**
 * O(n) solution - two pointer approach
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left<right) {
            int val = numbers[left] + numbers[right];
            if(val==target) return {left+1, right+1};
            if((numbers[left] + numbers[right]) > target) --right;
            else left++;
        }
        return numbers;
    }
};