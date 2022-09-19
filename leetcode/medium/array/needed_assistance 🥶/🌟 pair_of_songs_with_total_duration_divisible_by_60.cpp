// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

/**
 * LOGIC: O(N^2) solution is clearly the first approach
 * - Optimized approach is in O(N) where we can pick the remainders! How?
 * - First understand that if we have 40, then we need to check 60 - ('40'%60) = 20 so find how many 20's are there
 * - As in if we have 80 -> that's a 20! because 40+80 will be 120 which is divisible by 60 and hence a valid pair!
 * - We can keep incrementing the remainders we find so that if we have 2 remainders then we can simply add them to result
 * - Why add them to result? because that's the number of new pairs we generate when a new number is added to it
 */ 
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int, int> store;
        
        int result=0;
        for(int i=0;i<time.size();i++) {
            int toFind = 60-(time[i]%60);
            if(toFind==60) toFind=0;
            if(store.find(toFind)!=store.end()) {
                result+=store[toFind];
            }
            store[time[i]%60]++;
        }
        return result;
    }
};