// https://leetcode.com/problems/valid-sudoku/


/**
 * Problem requires understanding of hashing.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> row;
        unordered_map<int, set<char>> col;
        map<pair<int, int>, set<char>> grid;

        // pre processing for row col
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]!='.') {
                    // check in row present
                    if(row[i].find(board[i][j])!=row[i].end()) return false;

                    // check in column present
                    if(col[j].find(board[i][j])!=col[j].end()) return false;
                
                    // check in grid present
                    set<char> findInGrid = grid[{i/3, j/3}];
                    if(findInGrid.find(board[i][j])!=findInGrid.end()) return false;

                    // fill up if not present
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    grid[{i/3, j/3}].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};