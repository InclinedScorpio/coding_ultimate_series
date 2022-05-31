// https://leetcode.com/problems/majority-element/

/**
 * LOGIC: To understand Moore's Voting Algorithm
 * - Start counting a num / as if that's the max present
 * - If the count goes down to 0, immediately pick currentInt as the new item
 * - At last, some num will remain, that's the majority element
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(1)
 *
 */ 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int ongoingInt=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(ongoingInt==nums[i]) count++;
            else {
                if(count==1) {
                    ongoingInt = nums[i];
                    continue;
                } else count--;
            }
        }
        return ongoingInt;
    }
};