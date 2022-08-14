// https://leetcode.com/problems/minimum-path-sum/

/**
 * LOGIC: Multiple ways are possible hence we need to implement recursion here
 * - As multiple sub problems are possible hence we cn implement dp here
 * 
 */ 
class Solution {
public:
    int helper(vector<vector<int>>& grid, int ind, int jnd, vector<vector<int>>& gridRemember) {
        if(ind>=grid.size() || jnd>=grid[0].size()) return INT_MAX;
        if(gridRemember[ind][jnd]!=-1) return gridRemember[ind][jnd];
        if(ind==grid.size()-1 && jnd==grid[0].size()-1) return grid[ind][jnd];
        
        int bottom = helper(grid, ind+1, jnd, gridRemember);
        int right = helper(grid, ind, jnd+1, gridRemember);
        
        if(bottom==INT_MAX) return gridRemember[ind][jnd] = right + grid[ind][jnd];
        if(right == INT_MAX) return gridRemember[ind][jnd] = bottom + grid[ind][jnd];
        return gridRemember[ind][jnd] = min(bottom, right) + grid[ind][jnd];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> store(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(grid, 0, 0, store);
    }
};
