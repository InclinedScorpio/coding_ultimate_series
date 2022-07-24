// https://leetcode.com/problems/search-a-2d-matrix-ii/

/**
 * LOGIC: See 2d matrix as a tree - starting from the top right corner
 * - Now go left if value is greater than target
 * - And go down if value is smaller than target
 * 
 * COMPLEXITY: O(M+N)
 * - M+N will be in case the target is at lower left corner
 */ 
class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int target, int i, int j) {
        if(i>=matrix.size() || j<0 || matrix[i][j]<target || (j==0 && matrix[i][j]>target)) return false;
        if(matrix[i][j]==target) return true;
        if(j!=0 && matrix[i][j-1]>=target)
            return helper(matrix, target, i, j-1); 
        else
            return helper(matrix, target, i+1, j);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search greater item first in last
        for(int i=0;i<matrix.size();i++) {
            if(matrix[i][matrix[i].size()-1]>=target)
                return helper(matrix, target, i, matrix[i].size()-1);
        }
        return false;
    }
};