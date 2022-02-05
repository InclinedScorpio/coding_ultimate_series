// https://leetcode.com/problems/longest-consecutive-sequence/


/**
 * LOGIC: We know map gives the keys sorted when asked 
 * - Store the items in map 
 * - Now start iterating and keep checking if earlier number was already there or not in map - O(1)
 * - If it was there, increment counter (and save counter if it's maximum)
 * - If it wasn't decrement counter
 * 
 * - At last return the max counter and do +1 as the first element in longest sequence was not taken into account in above strategy
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) { //edge case, bad practice :)
            return 0;
        }
        
        map<int, int> store; //store will keep the keys which are present
        
        for(int i=0;i<nums.size();i++) { //fill up the store
            store[nums[i]]=1;
        }
        
        int maxCounter=0, counter=0; //will help us to store max counter value and current counter
        for(auto i: store) { //start iterating over store
            if(store.find(i.first -1) != store.end()) { // check for previous key in store, if present that means it's part of sequence
                counter++;
                if(maxCounter<counter) {
                    maxCounter = counter;
                }
            }else { // if chain breaks, i.e previous value is not present in store, just reset the counter
                counter=0;
            }
        }
        return maxCounter+1;
    }
};
