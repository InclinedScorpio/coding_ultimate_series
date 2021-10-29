// https://leetcode.com/problems/number-of-good-pairs/

/**
 * 1. Formula or math to calculate, no of similar pairs.
 * it's Sum of (N*N-1)/2, N is no of times a a no repeated.
 *
 * 2. Iterating through a map.
 *
 **/

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> store;
        for(int i=0;i<nums.size();i++) {
            if(store.find(nums[i])!= store.end()) {
                store[nums[i]] +=1;
            }else {
                store[nums[i]] = 1;
            }
        }
        
        // loop through the map
        map<int,int>::iterator it;
        int good_pairs=0;
        for(auto it=store.begin();it!=store.end();it++) {
            if(it->second>=2){
                good_pairs+=((it->second)*(it->second-1))/2;
            }
        }
        return good_pairs;
    }
};