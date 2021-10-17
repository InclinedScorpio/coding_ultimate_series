// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ansVect;
        map<int, int> valIndex;
        for(int i=0;i<nums.size();i++) {
            int newNum=nums[i];
            if(i==0){
                valIndex[newNum] = i;
                continue;            
            }
            // now check target-newNum already avail in map or not
            int numToFind = target-newNum;
            if(valIndex.find(numToFind) != valIndex.end()) {
                // number found
                ansVect.push_back(valIndex[numToFind]);
                ansVect.push_back(i);
                return ansVect;
            }
            valIndex[newNum] = i;
        }
        // exactly one solution: flow never reaches here
        return ansVect;
    }
};