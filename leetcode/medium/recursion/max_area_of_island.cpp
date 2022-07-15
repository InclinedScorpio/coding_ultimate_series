// https://leetcode.com/problems/max-area-of-island/


/**
 * LOGIC: Basic recursion, just need to see question and understand it's recursion
 * 
 */ 
class Solution {
public:
    int helper(vector<vector<int>>& grid, int ind, int jnd) {
        if(ind>=grid.size() || ind<0 || jnd>=grid[ind].size() || jnd<0 || grid[ind][jnd]==0
           || grid[ind][jnd]==2) 
            return 0;
        
        grid[ind][jnd] = 2; //mark reached
        
        int sumUp=1;
        // left
        sumUp+=helper(grid, ind, jnd-1);
        // right
        sumUp+=helper(grid, ind, jnd+1);
        // up
        sumUp+=helper(grid, ind-1, jnd);
        // down
        sumUp+=helper(grid, ind+1, jnd);
        return sumUp;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxVal=INT_MIN;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]==1) {
                    maxVal = max(maxVal, helper(grid, i, j));
                }
            }
        }
        return maxVal==INT_MIN ? 0 : maxVal;
    }
};