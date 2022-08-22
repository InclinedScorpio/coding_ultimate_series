// https://leetcode.com/problems/number-of-islands/

/**
 * LOGIC: Recursion basic problem
 * 
 */ 
class Solution {
public:
    void helper(vector<vector<char>>& grid, int ind, int jnd) {
        if(ind>=grid.size() || jnd>=grid[ind].size() || ind<0 || jnd<0) return;
        if(grid[ind][jnd]!='1') return;
        
        grid[ind][jnd] = '2';
        helper(grid, ind+1, jnd);
        helper(grid, ind, jnd+1);
        helper(grid, ind-1, jnd);
        helper(grid, ind, jnd-1);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    res++;
                    helper(grid, i, j);
                }
            } 
        }
        return res;
    }
};