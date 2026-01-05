// https://leetcode.com/problems/kth-largest-element-in-an-array/

/**
 * 
 * LOGIC
 * As no sorting is asked...
 * We can think of a max heap
 * Use heapify first to convert list to a max heap (give .begin and .end)
 * 
 * Then pop k-1 times as thats the largest O(klogn) - important
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> store(nums.begin(), nums.end());
        k--;
        while(k--) {
            store.pop();
        }
        return store.top();
        
    }
};