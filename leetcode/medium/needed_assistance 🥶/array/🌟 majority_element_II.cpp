// https://leetcode.com/problems/majority-element-ii/


/**
 * LOGIC:
 * - more than 1/3 means only 2 can be possible at max
 * - Why? as 1/3 + 1/3 + 1/3 = 1 so if >1/3 means only 2 is possible
 * 
 * - Has to be carried similar to majority element like Moores Algo
 * - Just that here 2 items needs to be checked
 * 
 * WHERE GOT CONFUSED:
 * Initial count are 0 and we check if count is 0, enter current item there
 * 
 * 
 * 
 */ 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int firstCount=0, secondCount=0;
        int first=INT_MIN, second=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==first) {
                firstCount++;
            } else if(nums[i]==second) {
                secondCount++;
            } else if(firstCount==0) { // note! update values if count 0
                first = nums[i];
                firstCount=1;
            } else if(secondCount==0) {
                second = nums[i];
                secondCount=1;
            } else {
                firstCount--;
                secondCount--;
            }
        }
            
        // as it's not given how many nums or even if it would exist, we need 
        // to check for both num if they are really >n/3 
        int firstTotal=0, secondTotal=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==first) firstTotal++;
            if(nums[i]==second) secondTotal++;
        }
        vector<int> result;
        if(firstTotal > nums.size()/3) result.push_back(first);
        if(secondTotal > nums.size()/3) result.push_back(second);
        return result;
    }
};