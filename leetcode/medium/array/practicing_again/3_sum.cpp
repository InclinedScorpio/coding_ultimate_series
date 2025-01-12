// https://leetcode.com/problems/3sum/description/

/**
 * Think about math A+B+C=0 so B+C=-A 
 * So if A is set, then we simply need to do 2Sum to see B and C exists for rest of records
 * So it will be a O(N^2) complexity
 * We will have to sort so that duplicates are not picked
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i=0;i<nums.size()-2;i++) {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int firstNum = nums[i];
            set<int> store;
            bool skipper=false;
            for(int j=i+1;j<nums.size();j++) {
                if(skipper && j!=i+1 && nums[j]==nums[j-1]) continue;
                skipper=false;
                int additionRequired = -(nums[i]);
                int toFind = additionRequired - nums[j];
                if(store.find(toFind)!=store.end()) {
                    // it exists
                    result.push_back({nums[i], toFind, nums[j]});
                    skipper=true;
                }
                store.insert(nums[j]);
            }
        }
        return result;
    }
};