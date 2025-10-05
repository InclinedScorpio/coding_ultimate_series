// https://leetcode.com/problems/pacific-atlantic-water-flow/description

/**
 * 
 * A normal dfs problem
 * - Remember to mark to unmark the current cell when backtracking -> path[i][j]=0;
 * 
 */
class Solution {
    public:
    
        bool isReachingPacific(vector<vector<int>>& heights, vector<vector<int>>& path, int i, int j) {
            if(i-1==-1 || j-1==-1) {
                path[i][j] = 2;
                return true;
            };
            if(path[i][j]==1) return false;
            if(path[i][j]==2) return true;
    
            path[i][j]=1;
    
            bool isReachableFromHere=false;
    
            // go top
            if(heights[i-1][j]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingPacific(heights, path, i-1, j));
            }
    
            // go bottom
            if(i+1!=heights.size() && heights[i+1][j]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingPacific(heights, path, i+1, j));
            }
    
            // go left
            if(heights[i][j-1]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingPacific(heights, path, i, j-1));
            }
    
            // go right
            if(j+1!=heights[0].size() && heights[i][j+1]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingPacific(heights, path, i, j+1));
            }
    
            if(isReachableFromHere) {
                path[i][j] = 2;
            } else {
                path[i][j]=0;
            }
            return isReachableFromHere;
        }
    
        bool isReachingAtlantic(vector<vector<int>>& heights, vector<vector<int>>& path, int i, int j) {
            if(i+1==heights.size() || j+1==heights[0].size()) {
                path[i][j] = 2;
                return true;
            };
    
            if(path[i][j]==1) return false;
            if(path[i][j]==2) return true;
    
            path[i][j]=1;
    
            bool isReachableFromHere=false;
    
            // go top
            if(i-1!=-1 && heights[i-1][j]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingAtlantic(heights, path, i-1, j));
            }
    
            // go bottom
            if(heights[i+1][j]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingAtlantic(heights, path, i+1, j));
            }
    
            // go left
            if(j-1!=-1 && heights[i][j-1]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingAtlantic(heights, path, i, j-1));
            }
    
            // go right
            if(heights[i][j+1]<=heights[i][j]) {
                isReachableFromHere = max(isReachableFromHere, this->isReachingAtlantic(heights, path, i, j+1));
            }
    
            if(isReachableFromHere) {
                path[i][j] = 2;
            }else {
                path[i][j]=0;
            }
            return isReachableFromHere;
        }
    
    
        bool isReachingBothOcean(vector<vector<int>>& heights, vector<vector<int>>& pacific, vector<vector<int>>& atlantic, int i, int j) {
            bool isPacificReachable = this->isReachingPacific(heights, pacific, i, j);
            bool isAtlanticReachable = this->isReachingAtlantic(heights, atlantic, i, j);
            if(isPacificReachable && isAtlanticReachable) return true;
            return false;
        }
    
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            vector<vector<int>> result;
            vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));
            vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));
            for(int i=0;i<heights.size();i++) {
                for(int j=0;j<heights[0].size();j++) {
                    if(this->isReachingBothOcean(heights, pacific, atlantic, i, j)) {
                        result.push_back({i, j});
                    }
                }
            }
    
            return result;
        }
    };