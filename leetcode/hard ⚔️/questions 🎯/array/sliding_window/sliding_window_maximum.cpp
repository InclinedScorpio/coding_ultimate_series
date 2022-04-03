// https://leetcode.com/problems/sliding-window-maximum/

/**
 * LOGIC: Sliding window!
 * - Main logic is to use map and to keep a check what all items are present in window
 * - Map keeps list sorted using the keys, so make use of it
 * 
 */ 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxValue=INT_MIN;
        vector<int> result;
        int lastInsertedIndex=0;
        map<int,int> store;
        for(int i=0;i<k;i++) {
            store[nums[i]]++;
        }
        maxValue=store.rbegin()->first;
        
        result.push_back(maxValue);
        
        for(int i=k;i<nums.size();i++) {
            store[nums[i]]++;
            store[nums[lastInsertedIndex]]--;
            if(store[nums[lastInsertedIndex]]==0) {
                store.erase(nums[lastInsertedIndex]);
            }
            lastInsertedIndex++;
            maxValue=store.rbegin()->first;
            result.push_back(maxValue);
        }
        
        return result;
    }
};
