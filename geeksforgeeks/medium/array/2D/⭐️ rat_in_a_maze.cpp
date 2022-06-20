// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

/**
 * LOGIC: Basic recursion only
 * - Make sure to block the grid once you reached, so you don't come back their again
 * - Unblock it after all ways are checked
 * 
 * COMPLEXITY: O(3^(N^2))
 * - Why 3? - because one possibility of going back to the direction from where you came from can be neglected as it won't be feasible
 *  
 */ 
class Solution{
    public:
    void helper(vector<vector<int>>& m, int i, int j, string str, vector<string>& result) {
        if(i==m.size() || j==m[0].size() || i==-1 || j==-1) return;
        if(m[i][j]==0) return;
        if(i==m.size()-1 && j==m[0].size()-1)  {
            result.push_back(str);
            return;
        }
        m[i][j]=0;
        helper(m, i+1, j, str+"D", result);
        helper(m, i, j+1, str+"R", result);
        helper(m, i-1, j, str+"U", result);
        helper(m, i, j-1, str+"L", result);
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        helper(m, 0, 0, "", result);
        return result;
    }
};