// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

/**
 * 
 * Problem is to understand that it uses normal bfs traversal to find the shortest path
 * DFS will not work as we need to find the shortest path, works but takes too long!
 */
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        if(grid[0][0]==1) return -1;
        q.push({0, 0});
        isVisited[0][0] = 1;
        int minimalDistance=1;
        while(!q.empty()) {
            int qSize = q.size();

            for(int qSizeIter=0;qSizeIter<qSize;qSizeIter++) {
                pair<int, int> front = q.front();
                if(front.first == grid.size()-1 && front.second == grid[0].size()-1) return minimalDistance;
                q.pop();
                for(int i=front.first-1;i<=front.first+1;i++) {
                    for(int j=front.second-1;j<=front.second+1;j++) {
                        if(i==front.first && j==front.second) continue;
                        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) continue;
                        if(isVisited[i][j]==0 && grid[i][j]==0) {
                            isVisited[i][j] = 1;
                            q.push({i, j});
                        }
                    }
                }
            }
            ++minimalDistance;
        }
        return -1;
    }
};