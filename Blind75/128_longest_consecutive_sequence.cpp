// https://leetcode.com/problems/longest-consecutive-sequence/description


/**
 * LOGIC: is to understand to use set to get it in O(n)
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> checked;
        int maxResult=0;

        for(int i: nums) {
            checked.insert(i);
        }

        for(int i=0;i<nums.size();i++) {
            // pick i
            int curr = nums[i];
            if(checked.find(curr)==checked.end()) continue;
            checked.erase(curr);
            // check right
            int currResult=1;
            while(checked.find(++curr)!=checked.end()) {
                    checked.erase(curr);
                    currResult++;
            }
            curr = nums[i];
            while(checked.find(--curr)!=checked.end()) {
                    checked.erase(curr);
                    currResult++;
            }
            maxResult = max(maxResult, currResult);
        }
        return maxResult;
    }
};