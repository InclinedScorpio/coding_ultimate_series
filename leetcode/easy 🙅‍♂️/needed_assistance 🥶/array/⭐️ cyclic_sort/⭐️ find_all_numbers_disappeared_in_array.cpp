// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

/**
 * LOGIC: Use cyclic sort
 * @CYCLIC SORT :
 * - Sorts items in O(1) - how? ?
 * - Condition: only possible when range [1, N] or [0, N] ....
 * - Just swap no. to their correct position
 * 
 * IN THIS QUESTIONS some no. are repeated and hence some are missing from 1,N
 * - Use Cyclic sort,
 * - As no. are from [0, N] - so '1' should be at (i-1)==0th position
 * - If already no. is sitting at required position, don't swap
 * - At last the repeatable no. will auto come to position which are missing
 * - "Why? because other no. will swap and come to their real position" - IMPORTANT
 * 
 * COMPLEXITY: O(N)
 * SPACE COMPLEXITY - O(1)
 * 
 */ 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++) {
            if(i!=(nums[i]-1)) {
                if(nums[nums[i]-1]!=nums[i]) {
                    swap(nums[nums[i]-1], nums[i]);
                    i--;
                }
            }
        }
        
        vector<int> result;
        for(int i=0;i<nums.size();i++) 
            if(i!=nums[i]-1) result.push_back(i+1);    
        
        return result;
    }
};
