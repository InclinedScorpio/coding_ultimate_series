// https://leetcode.com/problems/combination-sum-ii/

/**
 * NOTE: Try your own!
 * LOGIC: Similar to combination sum problem
 * - Here we aren't allowed duplicates
 * 
 * - Point to note is not to recurse using same item which we already recursed with
 */ 
class Solution {
public:

    void helper(vector<int>& candidates, int target, int iter, vector<int> vec, vector<vector<int>>& resStore) {
        if(target==0) {
            resStore.push_back(vec);
            return;
        } else if(target < 0) return;
        for(int i=iter;i<candidates.size();i++) {
            if(i>iter && candidates[i]==candidates[i-1]) continue;
            vec.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, vec, resStore);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> resStore;
        helper(candidates, target, 0, {}, resStore);
        return resStore;
    }
};