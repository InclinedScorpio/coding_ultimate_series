// https://leetcode.com/problems/permutations/description/

class Solution {
private:
    set<vector<int>> result;
public:
    void helper(vector<int>& nums, vector<int> curr, int i, unordered_set<int> dp) {
        if(i==nums.size()) return;
        if(dp.find(i)!=dp.end()) return;

        
        this->helper(nums, curr, i+1, dp);
        curr.push_back(nums[i]);
        dp.insert(i);

        if(curr.size()==nums.size()) {
            result.insert(curr);
            return;
        }

        for(int iter=0;iter<nums.size();iter++) {
            if(dp.find(iter)==dp.end()) {
                this->helper(nums, curr, iter, dp);
            }
        }
        return;
    }



    vector<vector<int>> permute(vector<int>& nums) {
        this->helper(nums, {}, 0, {});
        vector<vector<int>> finalRes;
        for(vector<int> r: result) {
            finalRes.push_back(r);
        }
        return finalRes;
    }
};