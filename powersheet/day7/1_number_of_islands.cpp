// https://leetcode.com/problems/number-of-islands/description/?utm_source=chatgpt.com

class Solution {
public:
    void processIslands(vector<vector<char>>& grid, int i, int j) {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return;
        if(grid[i][j]=='0' || grid[i][j]=='2') return;
        grid[i][j]='2';
        this->processIslands(grid, i+1, j);
        this->processIslands(grid, i, j+1);
        this->processIslands(grid, i-1, j);
        this->processIslands(grid, i, j-1);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    result++;
                    this->processIslands(grid, i, j);
                }
            }
        }
        return result;
    }
};