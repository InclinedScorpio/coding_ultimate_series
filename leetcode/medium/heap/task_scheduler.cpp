// https://leetcode.com/problems/task-scheduler/

/**
 * Logic is that:
 * - We need to find the task which has max frequency
 * - Because that will be the task which will be executed first
 * - If we take any other task first, it won't be optimal as we need min
 * - Hence, we need to take the task which has max frequency
 * 
 * - We don't need to store A, B, C.....
 * - Just numbers will be enough
 * - Once you process number, push it to queue so that you can pull when time is reached
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int currentInterval=0;

        priority_queue<int> maxHeap;

        unordered_map<char, int> counter;
        for(const char task: tasks) {
            counter[task]++;
        }
        
        for(auto charCount: counter) {
            maxHeap.push(charCount.second);
        }

        queue<pair<int, int>> secondaryStore;

        int index=0;
        while(index<tasks.size()) {
            if(!maxHeap.empty()) {
                int top = maxHeap.top();
                maxHeap.pop();
                --top;
                if(top>0)
                    secondaryStore.push({currentInterval + n + 1, top});
                index++;
            } 
            ++currentInterval;
            // check if something new has to be pulled
            if(!secondaryStore.empty()) {
                while(!secondaryStore.empty() && secondaryStore.front().first<=currentInterval) {
                    maxHeap.push(secondaryStore.front().second);
                    secondaryStore.pop();
                }
            }
        }
        return currentInterval;
    }

};