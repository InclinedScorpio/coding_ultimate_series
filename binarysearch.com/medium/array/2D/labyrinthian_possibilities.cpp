// https://binarysearch.com/problems/Labyrinthian-Possibilities

/**
 * Basic, use scratch paper!
 * LOGIC: point to note was to take 2 and more when path is there
 * - For first row obviously only one way is possible  - to repeat 2 (which means 1st way)
 * - For first column obviously only one way is possible - repeat 2
 * - Now at each index, add up and left value if they are not 1
 * - Make sure to remember up and left are (value-1)
 * 
 * COMPLEXITY: O(N^2)
 */ 
int solve(vector<vector<int>>& matrix) {
    bool wallReached=false;
    for(int i=0;i<matrix[0].size();i++) {
        if(wallReached || matrix[0][i]==1)  {
            wallReached=true;
            matrix[0][i] = 1;
            continue;
        }
            matrix[0][i] = 2;
    }
    wallReached = false;
    for(int i=0;i<matrix.size();i++) {
        if(wallReached || matrix[i][0]==1) {
            wallReached=true;
            matrix[i][0] = 1;
            continue; 
        }
        matrix[i][0] = 2;
    }

    //logic
    for(int i=1;i<matrix.size();i++) {
        for(int j=1;j<matrix[i].size();j++) {
            if(matrix[i][j]==1) continue;
            if(matrix[i-1][j]==1 && matrix[i][j]==1) matrix[i][j]=1;
            else if(matrix[i-1][j]==1 && matrix[i][j-1]!=1) matrix[i][j]=fmod(matrix[i][j-1], (pow(10,9) + 7));
            else if(matrix[i][j-1]==1 && matrix[i-1][j]!=1) matrix[i][j]=fmod(matrix[i-1][j], (pow(10,9) + 7));
            else {
                matrix[i][j] = fmod((matrix[i-1][j]-1) + (matrix[i][j-1]-1) + 1, pow(10,9) + 7);
            }
        }
    }
    
    return matrix[matrix.size()-1][matrix[0].size()-1]-1;
}