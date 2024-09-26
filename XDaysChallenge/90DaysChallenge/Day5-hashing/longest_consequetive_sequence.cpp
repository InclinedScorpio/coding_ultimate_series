// https://leetcode.com/problems/longest-consecutive-sequence/?submissionId=1402555783

/**
 * Problem requires understanding of hashing.
 * map makes use of tree (logN) for insertion, searching
 * unordered_map makes use of hashing (O(1)) for insertion, searching
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //keep items in hashmap
        unordered_set<int> store;
        for(int i: nums) {
            store.insert(i);
        }

        // ------
        int returnResponse=0;
        for(int i=0;i<nums.size();i++) {
            int result=1;
            int currNum = nums[i];
            int currNumForR = currNum;
            if(store.find(currNum)==store.end()) continue;
            // check backside
            int conseqtiveVal=0;
            while(store.find(--currNum)!=store.end()) {
                conseqtiveVal++;
                store.erase(currNum);
            }
            while(store.find(++currNumForR)!=store.end()) {
                conseqtiveVal++;
                store.erase(currNumForR);
            }
            result = result + conseqtiveVal;
            returnResponse = max(returnResponse, result);
        }
        return returnResponse;
    }
};