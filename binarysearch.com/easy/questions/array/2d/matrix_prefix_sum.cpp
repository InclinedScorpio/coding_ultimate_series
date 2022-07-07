// https://binarysearch.com/problems/Matrix-Prefix-Sum

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (j != 0) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (i != 0) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
    }

    return matrix;
}