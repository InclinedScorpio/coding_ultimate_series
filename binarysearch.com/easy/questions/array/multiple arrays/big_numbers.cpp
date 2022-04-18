// https://binarysearch.com/problems/Big-Numbers

int solve(vector<vector<int>>& m) {
    map<int, int> row;
    map<int, int> col;
    int rowMax=INT_MIN, colMax=INT_MIN;

    for(int i=0;i<m.size();i++) {
        rowMax=INT_MIN;
        for(int j=0;j<m[i].size();j++) {
            if(m[i][j]>rowMax) {
                rowMax = m[i][j];
            }
        }
        row[i]=rowMax;
    }
    for(int i=0;i<m[0].size();i++) {
        colMax=INT_MIN;
        int colInd=0;
        for(int j=0;j<m.size();j++) {
            if(m[j][i]>colMax) {
                colMax = m[j][i];
            }
        }
        col[i]=colMax;
    }
    int count=0;
    for(int i=0;i<m.size();i++) {
        for(int j=0;j<m[i].size();j++) {
            if(m[i][j]==row[i] && m[i][j]==col[j]) {
                count++;
            }
        }
    }
    return count;
}