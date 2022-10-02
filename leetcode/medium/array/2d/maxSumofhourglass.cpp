// https://leetcode.com/contest/weekly-contest-313/problems/maximum-sum-of-an-hourglass/

/**
 * LOGIC: Just check all possible points, that's all.
 * 
 */ 
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxSum=0;
        for(int i=0;i<grid.size()-2;i++) {
            for(int j=1;j<grid[i].size()-1;j++) {
                maxSum = max(maxSum, grid[i][j-1]+grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j]+grid[i+2][j-1] +grid[i+2][j+1]);
            }
        }
        return maxSum;
    }
};