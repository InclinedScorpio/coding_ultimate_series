// https://leetcode.com/problems/top-k-frequent-elements/


/**
 * LOGIC: Unordered_map + priority queue can help finding top k frequent elements
 * 
 */ 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        for(int i=0;i<nums.size();i++)
            store[nums[i]]++;
        
        priority_queue<pair<int, int>> maxHeap;
        
        int ind=0;
        vector<int> result;
        for(auto s: store) {
            ind++;
            maxHeap.push({s.second, s.first});
        }
        while(k--) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};