// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<int>> rows, col;
        map<pair<int, int>, unordered_set<int>> box;

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]=='.')continue;
                
                // check row
                if(rows[i].find(board[i][j])!=rows[i].end()) {
                    return false;
                }
                rows[i].insert(board[i][j]);

                // check col
                if(col[j].find(board[i][j])!=col[j].end()) {
                    return false;
                }
                col[j].insert(board[i][j]);

                // check box
                pair<int, int> b= {i/3, j/3};
                if(box[b].find(board[i][j])!=box[b].end()) {
                    return false;
                }
                box[b].insert(board[i][j]);
            }
        }
        return true;
    }
};