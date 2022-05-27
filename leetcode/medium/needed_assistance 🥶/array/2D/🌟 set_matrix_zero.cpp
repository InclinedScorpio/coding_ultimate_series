// https://leetcode.com/problems/set-matrix-zeroes/

/**
 * LOGIC: Question is easy if we can take additional space
 * - In that case we can take 2 vector representing rows and column
 * - And can mark 0 where whole row/column needs to be turned to 0
 * 
 * BUT HERE WE ARE NOT REQUIRED TO TAKE ANY EXTRA SPACE
 * - Hence, we are going to take 1st row and 1st column similar to how we discussed extra vector
 * - But how will this work?
 * 
 * - First we will see if the row or column (1st) needs to be turned to 0 at last or not
 * - Now we will start from 1,1 and go all the way down checking and converting row and column (1st) to 0 where required
 * - Once all are done, we will start checking which row/column (1st) are 0 and turning the complete row/column as 0
 * - finally we will check if row/colum (1st) are required to be turned to 0 completely or not
 * - If 0,0 is 0 that means whole left/right are required to be turned to 0 at end
 * 
 * COMPLEXITY: O(N^2)
 * SPACE: O(1)
 * 
 */ 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool topRowZero=false;
        for(int i=0;i<matrix[0].size();i++) 
            if(matrix[0][i]==0) topRowZero=true;
        
        bool leftColumnZero=false;
        for(int i=1;i<matrix.size();i++) 
            if(matrix[i][0]==0) leftColumnZero = true;
        
        // turn topmost/leftmost row/column zero if item==0
        for(int i=1;i<matrix.size();i++) {
            for(int j=1;j<matrix[i].size();j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        // top to bottom
        for(int i=1;i<matrix[0].size();i++) {
            if(matrix[0][i]==0)
                for(int j=1;j<matrix.size();j++)
                       matrix[j][i]=0;
        }
        
        // left to right
        for(int i=1;i<matrix.size();i++) {
            if(matrix[i][0]==0)
                for(int j=1;j<matrix[i].size();j++)
                    matrix[i][j]=0;
        }
        
        // if 0, 0 itself is 0 means both topRow, leftColumn will be all 0
        if(matrix[0][0]==0)  {
            topRowZero=true;
            leftColumnZero=true;
        }
        
        // turn TopRow 0 if required
        if(topRowZero) {
            for(int i=0;i<matrix[0].size();i++) {
                matrix[0][i]=0;
            }
        }
        
        // turn leftColumnZero if required
        if(leftColumnZero) {
            for(int i=0;i<matrix.size();i++) {
                matrix[i][0]=0;       
            }
        }
     }
};