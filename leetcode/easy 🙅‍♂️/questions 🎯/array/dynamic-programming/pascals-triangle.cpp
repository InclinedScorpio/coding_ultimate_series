// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        
        numRows--;
        int rows = 2;
        while(numRows) {
            vector<int> row(rows, 1);
            for(int i=1;i<row.size()-1;i++)
                row[i] = result[rows-2][i-1] + result[rows-2][i];
            result.push_back(row);
            rows++; numRows--;
        }
        return result;
    }
};