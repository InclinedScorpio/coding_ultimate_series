// https://leetcode.com/problems/rotting-oranges/

/**
 * LOGIC: DFS won't help, so we thought about BFS(queue method)
 * - It looks promising to use queue as we will carry those grid which are rotten
 * - And one by one extract and rott the adjacent ones and push them into the queue
 * 
 * - In each iteration we will check how many total oranges went in queue
 * - Which can be matched with the total oranges we counted intially in the 2d array
 * - If they match we return the DAYS taken to rott
 * 
 * COMPLEXITY: O(N^2)
 * - because Max places oranges can occur is everywhere
 * 
 */ 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> store;
        int totalOranges=0;
        
        // prepare rotten oranges in queue
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]==1 || grid[i][j]==2) totalOranges++;
                if(grid[i][j]==2) {
                    store.push({i, j});
                }
            }
        }

        int currSize=store.size();
        int orangesEncountered=currSize;
        int days=-1;
        while(currSize>0) {
            for(int i=0;i<currSize;i++) {
                int io = store.front().first;
                int jo = store.front().second;
                store.pop();
                if((io+1)<grid.size() && grid[io+1][jo]==1) {
                    grid[io+1][jo] = 2;
                    store.push({io+1, jo});
                }
                if((jo+1)<grid[io].size() && grid[io][jo+1]==1) {
                    grid[io][jo+1] = 2;
                    store.push({io, jo+1});
                }
                if((io-1)>=0 && grid[io-1][jo]==1) {
                    grid[io-1][jo] = 2;
                    store.push({io-1, jo});
                }
                if((jo-1)>=0 && grid[io][jo-1]==1) {
                    grid[io][jo-1] = 2;
                    store.push({io, jo-1});
                }
            }
            days++;
            orangesEncountered+=store.size();
            currSize = store.size();
        }
        if(orangesEncountered == totalOranges) return days>-1 ? days: 0;
        return -1;
    }
};