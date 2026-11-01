// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void helper(vector<int>& candi, int i, int curr, const int & target, vector<int> res, vector<vector<int>>& returnBck) {
        if (i==candi.size() || curr>target) return;
        if(curr==target) {
            returnBck.push_back(res);
            return;
        };

        // don't pick it, move
        this->helper(candi, i+1, curr, target, res, returnBck);

        // be at i, pick it
        res.push_back(candi[i]);
        this->helper(candi, i, curr + candi[i], target, res, returnBck);

        return;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> returnBck;
        this->helper(candidates, 0, 0, target, {}, returnBck);
        return returnBck;   
    }
};