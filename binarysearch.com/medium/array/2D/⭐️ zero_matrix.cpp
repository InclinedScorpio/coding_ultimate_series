// https://binarysearch.com/problems/Zero-Matrix


/**
 * LOGIC: Similar question as leetcode
 * - Question becomes complex when space O(1) is asked
 * 
 * Q) How to do it in O(1) space?
 * A) Consider 0th row and column as extra vector which we would have considered otherwise
 * - Initially just check if row and col neeeds to be turned to 0 at end
 * - Later just check data from 1,1 to last and turn respective 0th item in row and col as 0 
 * - Now just turn the whole row and column as 0
 * 
 * - At last see if 0th row and columns are required to be turned to be zero
 * 
 * COMPLEXITY: O(N^2)
 * SPACE: O(1)
 * 
 */ 
vector<vector<int>> solve(vector<vector<int>>& matrix) {

    bool isRowZero=false, isColZero=false;
    // corner is zero!
    if(!matrix[0][0]) {
        isRowZero=true;
        isColZero=true;
    } else {
        // check row
        for(int i=0;i<matrix[0].size();i++) {
            if(!matrix[0][i])  {
                isRowZero=true;
                break;
            }
        }
        // check col
        for(int i=0;i<matrix.size();i++) {
            if(!matrix[i][0]) {
                isColZero=true;
                break;
            }
        }
    }

    // check [1][1] to end && replace row start and col start with 0
    for(int i=1;i<matrix.size();i++) {
        for(int j=1;j<matrix[i].size();j++) {
            if(!matrix[i][j]) {
                matrix[i][0]= 0;
                matrix[0][j]=0;
            }
        }
    }

    // replace columns with 0
    for(int j=1;j<matrix[0].size();j++) {
        if(matrix[0][j]) continue;
        for(int i=1;i<matrix.size();i++) {
            matrix[i][j]=0;
        }
    }

    // replace rows with 0
    for(int i=1;i<matrix.size();i++) {
        if(matrix[i][0]) continue;
        for(int j=1;j<matrix[i].size();j++) {
            matrix[i][j]=0;
        }
    }

    // row to 0 if required
    if(isRowZero) {
        for(int i=0;i<matrix[0].size();i++) {
            matrix[0][i]=0;
        }
    }
    // col to 0 if required
    if(isColZero) {
        for(int j=0;j<matrix.size();j++) {
            matrix[j][0]=0;
        }
    }

    return matrix;
}