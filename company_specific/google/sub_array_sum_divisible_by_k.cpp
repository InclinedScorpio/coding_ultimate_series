// https://leetcode.com/problems/subarray-sums-divisible-by-k/

/**
 * In cpp, the % operator can return negative values for negative numbers.
 * we need to ensure after taking %k, the result is always non-negative so add k if negative.
 * This is important to ensure that the map keys are always non-negative.
 * "This is a catch in this question, if you do not take care of this, you will get wrong answer"
 * 
 * LOGIC: Rather than checking each subarray, we can use prefix sums and a hashmap to count how many times each remainder has occurred.
 * This problem is similar to the "subarray sum equals k" problem, but instead of checking for a specific sum, we check for sums that are divisible by k.
 */
class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            int result=0;
    
            // find presum
            int sum=0;
            vector<int> store;
            for(int num: nums) {
                sum+=num;
                store.push_back(sum);
            }
            // presum ready
    
            // do math head - check at each step - how many %k already seen
            unordered_map<int, int> checker;
            checker[0]++; // [5], cases when all have to be considered
            for(int store_num: store) {
                int div = store_num%k >=0 ? store_num%k : ((store_num%k)+k);
                result += checker[div];
                checker[div]++;
            }
            return result;
        }
    };
    