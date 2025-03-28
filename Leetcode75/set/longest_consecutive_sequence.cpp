// https://leetcode.com/problems/longest-consecutive-sequence/

/**
 * @logic: use unordered_set to store the elements - O(1) in all operations
 * 1. insert all the elements in the set
 * 2. iterate over the set and check if the curr element is the starting of a sequence
 * 3. if it is, then check for the next elements in the sequence
 * 4. if it is not, then continue
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store;
        for(int i: nums) {
            store.insert(i);
        }

        int result=0;
        for(int curr: store) {
            int updatedCurr = curr;
            int currCount=0;
            if(store.find(curr - 1)==store.end()) {
                currCount++;
                while(store.find(updatedCurr+1)!=store.end()) {
                    currCount++;
                    updatedCurr++;
                }
            } else {
                continue;
            }
            result = max(result, currCount);
        }
        return result;
    }
};