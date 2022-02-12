// https://binarysearch.com/problems/Flip-and-Invert-Matrix

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    vector<vector<int>> result;
    for(int i=0;i<matrix.size();i++) {
        vector<int> temp;
        for(int j=matrix[i].size()-1;j>=0;j--){
            if(matrix[i][j]) temp.push_back(0);
            else temp.push_back(1);
        }
        result.push_back(temp);
    }
    return result;
}
