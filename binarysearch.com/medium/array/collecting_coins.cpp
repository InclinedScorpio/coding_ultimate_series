// https://binarysearch.com/problems/Collecting-Coins

/**
 * LOGIC: Basic - think in terms of 2D Matrix
 * - Max at each point is either top + cell or left + cell
 * - Whatever is the max, that will be the result at each cell
 * 
 * COMPLEXITY: O(row * col)
 * 
 */ 
int solve(vector<vector<int>>& matrix) {
    int sum=0;
    for(int i=0;i<matrix[0].size();i++) {
        sum += matrix[0][i];
        matrix[0][i] = sum;
    }

    for(int i=1;i<matrix.size();i++) {
        for(int j=0;j<matrix[i].size();j++) {
            if(j==0)
                matrix[i][j] = max(matrix[i-1][j]+matrix[i][j], matrix[i][j]);
            else
                matrix[i][j] = max(matrix[i-1][j]+matrix[i][j], matrix[i][j-1] + matrix[i][j]);
        }
    }

    return matrix[matrix.size()-1][matrix[0].size()-1];   
}
