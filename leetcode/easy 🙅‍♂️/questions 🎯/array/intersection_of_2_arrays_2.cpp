// https://leetcode.com/problems/intersection-of-two-arrays-ii/

/**
 * LOGIC: Basic
 * 
 */ 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> store;
        for(int i: nums1) store[i]++;
        vector<int> result;
        for(int i: nums2) {
            if(store.find(i)!=store.end()) {
                result.push_back(i);
                if(store[i]==1) store.erase(i);
                else store[i]--;
            }
        }
        return result;
    }
};