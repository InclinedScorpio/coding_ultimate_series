// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1, 3
        // 2, 2,
        // 3, 1

        unordered_map<int, int> store;
        for(int num: nums) {
            store[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto st: store) {
            if(minHeap.size()<k) {
                minHeap.push({st.second, st.first});
            } else {
                if(minHeap.top().first<st.second) {
                    minHeap.pop();
                    minHeap.push({st.second, st.first});
                }
            }
        }
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};