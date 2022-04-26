// https://leetcode.com/problems/find-median-from-data-stream/

/**
 * LOGIC: Similar to running median
 * - As sorting everytime data change won't be feasible
 * - We see median is middle, & left is sorted, right sorted as well
 * - And in both left & right, we need max & min
 * - Hence, max & min can be easily implemented using maxHeap, minHeap
 * - This is intuition
 * 
 */ 
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    double currMedian=INT_MAX;
    
    MedianFinder() { }
    
    void addNum(int num) {
        if(currMedian>num) { // store left side
            if(maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        } else {
            if(minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } else {
                minHeap.push(num);
            }
        }
        
        if(maxHeap.size() > minHeap.size()) {
            currMedian = maxHeap.top();
        } else if(maxHeap.size() < minHeap.size()) {
            currMedian = minHeap.top();
        } else {
         currMedian = (maxHeap.top() + minHeap.top())/2.0;
        }
    }
    
    double findMedian() {
        return currMedian;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */