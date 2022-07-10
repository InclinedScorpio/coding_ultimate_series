// https://leetcode.com/problems/jump-game-vi/

/**
 * LOGIC: Initial logic is to understand O(N^2)
 * - As it gives TLE, we need to optimize
 * 
 * - If we see in detail at each index, we need to require the max value formed in previous k
 * - Hence in each index we can find the max value formed in previous k + current
 * - BUT, "max value in previous k"- can be done using MAX HEAP! - o(logN)
 * 
 * NOTE: Make sure to remove the indices <i-k as from there you can't reach i (k step max is possible)
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 
class Solution {
public:
    // O(nlogN)
    int helper(vector<int>& nums, int k, int ind, priority_queue<pair<int, int>>& pq) {
        int maxValTill = nums[ind];
        // remove stale indices outside k
        while(pq.size() && pq.top().second<ind-k) {
            pq.pop();
        }
        int maxBeforeInd = pq.size() ? pq.top().first : 0;
        maxValTill += maxBeforeInd; //add max present inside previous k to curr val
        pq.push({maxValTill, ind});
        //iterate - one step only*
        if(ind == nums.size()-1) return maxValTill;
        return helper(nums, k, ind+1, pq);
    }
    
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        return helper(nums, k, 0, pq);
    }
};