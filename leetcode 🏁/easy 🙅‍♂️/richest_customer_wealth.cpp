// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int max=0;
        for(int i=0;i<accounts.size();i++) { 
            int current_iter_max=0;
            for(int j=0;j<accounts[i].size();j++) {
                   current_iter_max+=accounts[i][j];
            }
            if(current_iter_max>max) {
                max=current_iter_max;
            }
        }
        return max;
    }
};