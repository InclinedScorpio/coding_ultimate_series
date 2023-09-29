https://leetcode.com/problems/subarray-sum-equals-k

/**
 * Question requires only understanding of prefix sum and hashmap
 * 
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int sum=0, res=0;
      unordered_map<int, int> store;
      store[0]++;
      for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if(store.find(sum-k)!=store.end()) res+=store[sum-k];
        store[sum]++;
      }
      return res;
    }
};