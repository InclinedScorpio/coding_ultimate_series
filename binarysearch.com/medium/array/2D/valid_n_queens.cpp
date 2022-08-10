// https://binarysearch.com/problems/Valid-N-Queens

/**
 * LOGIC: Basic recrursion problem
 * 
 */ 
bool helper(vector<vector<int>>& matrix, int row, int col) {

    // check top left
    int i = row-1, j=col-1;
    while(i>=0&&j>=0) {
        if(matrix[i][j]==1) return false;
        i--;
        j--;
    }

    // check top right
    i = row-1;j=col+1;
    while(i>=0 && j<matrix.size()) {
        if(matrix[i][j]==1) return false;
        i--;
        j++;
    }
    return true;
}


bool solve(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++) {
        bool isAlreadyFound=false;
        for(int j=0;j<matrix[i].size();j++) {
            if(matrix[i][j] && isAlreadyFound) return false;
            if(matrix[i][j]) {
                isAlreadyFound=true;
                if(!helper(matrix, i, j)) {
                    return false;
                }
            }
        }
        if(!isAlreadyFound) return false;
    }
    return true;
}