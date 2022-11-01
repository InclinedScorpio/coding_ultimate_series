// https://leetcode.com/problems/intersection-of-two-arrays/

/**
 * LOGIC: Basic
 * 
 */ 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> store;
        for(int i: nums1) {
            store.insert(i);
        }
        
        vector<int> result;
        for(int i: nums2) {
            if(store.find(i)!=store.end()) {
                result.push_back(i);
                store.erase(i);
            }
        }
        return result;
    }
};