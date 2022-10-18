// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

/**
 * LOGIC: Good Greedy Question
 * - Sorting is the first step which should come to mind as we are concerned with sequence here
 * - After sorting, the major part is to understand we need to implement greedy
 * - Also! We can only + and no -
 * - Hence if at any point previous num is greater or equal means we are required to increment current +1 greater than previous
 * - (Think it this way - previous must have passed through current num as we are doing +1 always - that only when it's ==) 
 * - Example - 1, 2, 2, 2, 3 - here  -> 1, 2, 3, 4, (3) - 3 now knows as previous is 4, it's true that previous somewhere 3-4 must be there, hence just increment more than 4
 */
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        unordered_map<int, int> store;
        int maxVal=INT_MIN;
        
        for(int num: nums) {
            store[num]++;
            maxVal=max(maxVal, num);
        }
        
        int increments=0;
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]>=nums[i]) {
                increments+=(nums[i-1]-nums[i]+1);
                nums[i] = nums[i-1]+1;
            }
        }
        return increments;
    }
};

