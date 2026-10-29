// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end()); //quicksort - O(NlogN)

        vector<vector<int>> result;

        for(int i=0;i<nums.size()-2;i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int prime=nums[i];
            unordered_map<int, int> store;
            unordered_set<int> s;
            for(int curr=i+1;curr<nums.size();curr++) {
                if(s.find(nums[curr])!=s.end()) continue;
                int toFind = -(prime + nums[curr]);
                if(store.find(toFind)!=store.end()) {
                    s.insert(nums[curr]);
                    result.push_back({prime, toFind, nums[curr]});
                }
                store[nums[curr]]++;
            }
        }
        return result;
    }
};