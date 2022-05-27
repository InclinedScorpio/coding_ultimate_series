// https://binarysearch.com/problems/Number-of-Islands

/**
 * LOGIC: Basic recursion problem, find number of islands
 * 
 */ 
bool helper(vector<vector<int>>& arr, int i, int j) {
    if(j<0 || i>=arr.size() || i<0 || j>=arr[0].size() || arr[i][j]==0 || arr[i][j]==-1) return false;

    arr[i][j]=-1;

    bool left = helper(arr, i, j-1);
    bool right = helper(arr, i, j+1);
    bool bottom = helper(arr, i+1, j);
    bool up = helper(arr, i-1, j);
    return true;
}

int solve(vector<vector<int>>& matrix) {
    int counter=0;
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[i].size();j++) {
             counter+=helper(matrix, i, j);
        }
    }
    return counter;
}