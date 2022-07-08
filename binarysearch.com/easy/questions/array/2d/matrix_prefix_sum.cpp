// https://binarysearch.com/problems/Matrix-Prefix-Sum

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    if(matrix.size()==0) return {};

    // top Row 
    int topRowSum=0;
    for(int j=0;j<matrix[0].size();j++) {
        topRowSum+=matrix[0][j];
        matrix[0][j] = topRowSum;
    }

    // apart from topRow
    for(int i=1;i<matrix.size();i++) {
        int sum=0;
        for(int j=0;j<matrix[i].size();j++) {
            sum+=matrix[i][j];
            matrix[i][j] = matrix[i-1][j] + sum;
        }
    }

    return matrix;
}