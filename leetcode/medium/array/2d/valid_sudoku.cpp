// https://leetcode.com/problems/valid-sudoku/

/**
 * LOGIC: Obviously top to bottom and left To right can be figured out
 * - Only LOGIC is to think how to represent the blocks to find repearing num
 * - Each block can be represented as 01, 11, 12...
 * - And this can be kept inside map which can further contains set to repsent...
 * - ... all numbers in that block!
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<string, set<char> > store;

        for(int i=0;i<9;i++) {
            set<char> leftToRight;
            set<char> upToDown;
            
            for(int j=0;j<9;j++) {
                //leftToRight
                if(board[i][j]!='.' && leftToRight.find(board[i][j])!=leftToRight.end()) return false;
                else leftToRight.insert(board[i][j]);
                
                //upToDown
                if(board[j][i]!='.' && upToDown.find(board[j][i])!=upToDown.end()) return false;
                else upToDown.insert(board[j][i]);    
                
                // checking blocks
                string currInd = to_string((int)(i/3)) + to_string((int)(j/3));
                cout<<currInd<<" "<<board[i][j]<<" | ";
                if(board[i][j]!='.' && store[currInd].find(board[i][j])!=store[currInd].end()) return false; 
                else store[currInd].insert(board[i][j]);
            }
        }
        return true;
    }
};