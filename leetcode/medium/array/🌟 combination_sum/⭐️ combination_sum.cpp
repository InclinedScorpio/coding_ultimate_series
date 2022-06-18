// https://leetcode.com/problems/combination-sum/

/**
 * LOGIC: Basic recursion
 * 
 * COMPLEXITY: O(2^N) * N
 * - either you pick or you don't so 2^N
 * - And N is because of copying the vector in each loop
 */ 
class Solution {
public:
    
    void helper(vector<int>& candidates, int target, int iter, vector<int> res, vector<vector<int>>& storeRes) {
        if(target==0) {
            storeRes.push_back(res);
            return;
        } else if(target<0) return;
        vector<int> saveRes = res;
        for(int i=iter;i<candidates.size();i++) {
            res.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, res, storeRes);
            res = saveRes;
        }
    }    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> storeRes;
            helper(candidates, target, 0, {}, storeRes);
            return storeRes;
    }
};