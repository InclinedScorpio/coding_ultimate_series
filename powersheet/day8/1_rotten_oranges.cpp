// https://leetcode.com/problems/rotting-oranges/description/?utm_source=chatgpt.com

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> store;

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]==2) {
                    store.push({i, j});
                }
            }
        }
        store.push({-1, -1});

        int result=0;
        int changed=0;
        while(!store.empty()) {
            pair<int, int> front = store.front();
            int i=front.first, j=front.second;
            
            store.pop();
            if(front==make_pair(-1, -1)) {
                if(changed) result++;
                changed=0;
                if(!store.empty()) {
                    store.push({-1, -1});
                } else break;
                continue;
            }

            if(i-1>=0 && grid[i-1][j]==1) {
                store.push({i-1, j});
                grid[i-1][j]=2;
                changed=1;
            }
            if(j-1>=0 && grid[i][j-1]==1) {
                store.push({i, j-1});
                grid[i][j-1]=2;
                changed=1;
            }
            if(i+1<grid.size() && grid[i+1][j]==1) {
                store.push({i+1, j});
                grid[i+1][j]=2;
                changed=1;
            }
            if(j+1<grid[0].size()&& grid[i][j+1]==1) {
                store.push({i, j+1});
                grid[i][j+1]=2;
                changed=1;
            }
        }

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return result;
    }
};