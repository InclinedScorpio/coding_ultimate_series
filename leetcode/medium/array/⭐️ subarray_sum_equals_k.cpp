// https://leetcode.com/problems/subarray-sum-equals-k/

/**
 * LOGIC: Start thinking from brute force
 * - To get sum we need to go through O(N^3).. how?
 * - Picking 2 ptr + doing sum of them in btw
 * 
 * - Now, think doing sum btw 0, 4, and 0, 3 is nearly same
 * - In these kind of cases we prefer prefix sum ! (Clue)
 * - Hence after building prefix sum, we understand we can simply do algebra
 * - To check if required part is there or not, how?
 * 
 * currentSum - (TO_FIND) = TARGET
 * Hence ( TO_FIND = currentSum - TARGET ) 
 * to_find elements we can store in hash table
 * 
 * COMPLEXITY: O(N)
 * 
 * 
 * 
 */ 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> store(nums.size(), 0);
        int sum=0;
        unordered_map<int, int> checker;
        int result = 0;
        checker[0] = 1; 
          
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            store[i]=sum;
            if(checker.find(store[i] - k)!=checker.end()) {
                result += checker[store[i] - k];
            }
            checker[store[i]]++;
        }
        return result;
    }
};
