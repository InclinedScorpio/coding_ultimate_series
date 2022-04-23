// https://leetcode.com/problems/sliding-window-maximum/

/**
 * LOGIC: We firstly need to maintain a window
 * - In the window we also need to maintain a double ended queue (deque)
 * - Why to maintain queue & how it will help to get next max in window?
 * - It's simple actually
 * - Eg. [1,3,-1, -3,5,3,6,7]
 * initially we have [1]
 * 1) push in dq: [1]
 * 2) [1,3]-> now as 3 came, we need to check & remove smaller ones
 * - Remove 1 and push 3 [3]
 * 3) [1,3,-1]
 * - As we have [3] in dq (greater), we will simpply push -1 in dq
 * - Why? because when 3 will be removed, it's possible that -1 becomes next largest
 * 4) [3,-1,-3]
 * - 1 got removed from starting & it was not the front of dq (it can't be any further)
 * 5) [-1, -3, 5]
 * - 3 got removed, and it was in dq also so from dq also remove it
 * - [3,-1, -3] - - > [-1, -3] - - > insert 5!
 * - remove -3 as smaller, remove -1 as well as smaller & push 5 => [5]
 * 
 * - So at each step... the front of deque is the max present!
 * - We made it possible by remove the smaller ones if present at back, and keeping big one at front
 * - Also, it worth noting that if smaller comes, add it as after removal of big one that may be the biggest present
 * - Anyhow, if any bigger comes, that smaller will anyhow will be replaced!
 * - That how deque helped to keep record of current biggest in O(N)
 * 
 * COMPLEXITY: O(2N)
 * 
 */ 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        
        vector<int> result;
        for(int i=0;i<k;i++) {
            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }
            // now insert
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        
        for(int i=k;i<nums.size();i++) {
            if(i-k == dq.front()) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }
        
        return result;
    }
};