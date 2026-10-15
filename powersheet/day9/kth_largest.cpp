https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums) {
            if(minHeap.size()<k) {
                minHeap.push(num);
            } else {
                if(minHeap.top()<num) {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
        int result=0;
        return minHeap.top();
    }
};