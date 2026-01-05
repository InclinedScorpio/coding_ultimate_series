// https://leetcode.com/problems/longest-consecutive-sequence/

/**
 * Blind 75 Problem
 * 
 * Longest Consecutive Sequence
 * Hashing must be used! - that's only thing required
 */
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
    
            unordered_map<int, int> store;
            for(int num: nums) {
                store[num]=1;
            }
    
            int result=0;
    
            for(int i=0;i<nums.size();i++) {
                int currNum=nums[i];
                int counter=1;
    
                // if found
                while(store.find(currNum-1)!=store.end()) {
                    store.erase(currNum-1);
                    counter++;
                    currNum--;
                }
                currNum=nums[i];
                while(store.find(currNum+1)!=store.end()) {
                    store.erase(currNum+1);
                    counter++;
                    currNum++;
                }
                store.erase(nums[i]);
    
                result=max(result, counter);
            }
            
            return result;
        }
    };