// https://leetcode.com/problems/rotate-image/

/**
 * LOGIC: If we see closely, the solution required is similar to Transpose
 * 
 * - TRANSPOSE: Is changing rows to columns
 * 1) But in solution we are required similar just the rows are reversed
 * 2) Hence we need to do transpose and then reverse the item in rows
 * 
 */ 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // transpose of matrix
        for(int i=0;i<matrix.size();i++) {
            for(int j=i+1;j<matrix[i].size();j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse now rowwise
        for(int i=0;i<matrix.size();i++) {
            int reverseInd = matrix.size()-1;
            for(int j=0;j<matrix[i].size()/2;j++) {
                swap(matrix[i][j], matrix[i][reverseInd]);
                reverseInd--;
            }
        }
    }
};