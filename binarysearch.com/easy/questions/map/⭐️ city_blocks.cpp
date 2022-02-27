// https://binarysearch.com/problems/City-Blocks

/**
 * LOGIC: 2d array and so looks like graph problem as distance needs to be find
 * Whereas, we just need to use hash table to keep location of string
 * 
 * Good Question!
 */ 
int solve(vector<vector<string>>& matrix, vector<string>& blocks) {
    map<string, pair<int,int> > store;
    
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[i].size();j++) {
            store[matrix[i][j]]={i,j};
        }
    }

    int steps=0;
    pair<int,int> currIndex={0,0};
    for(int i=0;i<blocks.size();i++) {
        steps += abs(currIndex.first-store[blocks[i]].first);
        steps += abs(currIndex.second-store[blocks[i]].second);
        currIndex = store[blocks[i]];
    }

    return steps;
}