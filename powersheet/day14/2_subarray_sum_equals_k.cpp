// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        int sum=0, res=0;
        store[0]++;

        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];

            if(store.find(sum-k)!=store.end()) {
                res+=store[sum-k];
            }
            store[sum]++;
        }
        return res;
    }
};