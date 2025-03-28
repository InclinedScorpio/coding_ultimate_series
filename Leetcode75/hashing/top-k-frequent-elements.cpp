// https://leetcode.com/problems/top-k-frequent-elements/

/**
 * LOGIC: We need to find top k frequent elements
 * - First think of using hashmap to store the frequency
 * - Now as we need optimzed soln, we will reverseHashmap to store the elements for each frequency
 * - NOTE_CORE_LOGIC: `THE MAX FREQUENCY CAN BE EQUAL TO THE SIZE OF THE ARRAY` AND THAT'S WHY WE NEED TO ITERATE FROM THE BACK
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> store;
        for(int i: nums) {
            store[i]++;
        }

        vector<vector<int>> checker(nums.size()+1);
        int maxVal=INT_MIN;
        for(auto keyVal: store) {
            checker[keyVal.second].push_back(keyVal.first);
            maxVal = max(maxVal, keyVal.second);
        }
        vector<int> result;
        for(int i=maxVal;i>=1;i--) {
            if(checker[i].size()==0) continue;
            vector<int>& temp = checker[i];
            for(int i=0;i<temp.size();i++) {
                result.push_back(temp[i]);
                if(result.size()==k) return result;
            }
        }
        return result;
    }
};