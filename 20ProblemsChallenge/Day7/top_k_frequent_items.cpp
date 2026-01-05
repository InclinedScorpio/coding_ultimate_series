// https://leetcode.com/problems/top-k-frequent-elements/description/

/**
 * Logic: 
 * The main point to reduce complexity is to understand...
 * how to use the minheap rather than max heap
 * - With max heap the complexity would be O(nlogn)
 * 
 * But we need to reduce it
 * so use a minheap whose max height will only reach k
 * because as soon as item is increasing k we will see if new item needs to be added or not
 * if new item is bigger then we pop and add it
 * if not then we skip it
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        for(int num: nums) {
            store[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto st: store) {
            if(minHeap.size()==k) {
                if(minHeap.top().first<st.second) {
                    minHeap.pop();
                } else {
                    continue;
                }
            }
            minHeap.push({st.second, st.first});
        }

        vector<int> result;
        while(k) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }
        return result;
    }
};