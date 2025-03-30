// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void usingDFS(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(grid[i][j]=='0' || grid[i][j]=='2') return;
        
        grid[i][j]='2'; // marked reached
        usingDFS(grid, i+1, j);
        usingDFS(grid, i-1, j);
        usingDFS(grid, i, j+1);
        usingDFS(grid, i, j-1);
    }

    void usingBFS(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int qSize = q.size();
            pair<int, int> pointer = q.front();
            for(int i=0;i<qSize;i++) {
                pair<int, int> ptr = q.front();
                q.pop();
                grid[ptr.first][ptr.second] = '2';
                // check neighbours
                if(ptr.first-1>=0 && grid[ptr.first-1][ptr.second]=='1') {
                    grid[ptr.first-1][ptr.second]='2';
                    q.push({ptr.first-1, ptr.second});
                } 
                if (ptr.first+1<grid.size() && grid[ptr.first+1][ptr.second]=='1') {
                    grid[ptr.first+1][ptr.second] = '2';
                    q.push({ptr.first+1, ptr.second});
                } 
                if(ptr.second+1<grid[0].size() && grid[ptr.first][ptr.second+1]=='1') {
                    grid[ptr.first][ptr.second+1] = '2';
                    q.push({ptr.first, ptr.second+1});
                }
                if(ptr.second-1>=0 && grid[ptr.first][ptr.second-1]=='1') {
                    grid[ptr.first][ptr.second-1] = '2';
                    q.push({ptr.first, ptr.second-1});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    ++result;
                    // usingDFS(grid, i, j);
                    usingBFS(grid, i, j);
                }
            }
        }
        return result;
    }
};