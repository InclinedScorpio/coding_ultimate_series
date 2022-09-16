// https://leetcode.com/problems/game-of-life/

/**
 * LOGIC: We need to do it inplace, so we can use some temp data to keep it there
 *
 **/
class Solution {
public:
    
    bool checkOne(vector<vector<int>>& board, int ind, int jnd) {
        if(ind<0 || jnd<0 || ind>=board.size() || jnd>=board[ind].size()) return false;
        if(board[ind][jnd]>0) return 1;
        else return 0;
    }
    
    void helper(vector<vector<int>>& board, int ind, int jnd) {
        // cout<<ind<<" | "<<jnd<<" | ";
        bool isCurrOne = board[ind][jnd]; // top 
        int totalOnes=0;
        totalOnes+=checkOne(board, ind-1, jnd-1); // top left
        totalOnes+=checkOne(board, ind-1, jnd); // top
        totalOnes+=checkOne(board, ind, jnd-1); // left
        totalOnes+=checkOne(board, ind+1, jnd); // bottom 
        totalOnes+=checkOne(board, ind, jnd+1); // right
        totalOnes+=checkOne(board, ind+1, jnd+1); // bottom right
        totalOnes+=checkOne(board, ind-1, jnd+1); //top right
        totalOnes+=checkOne(board, ind+1, jnd-1); // bottom left

        if(isCurrOne) {
            if(totalOnes==2 or totalOnes==3) return; //lives
            // make it die temporarily
            if(totalOnes<2 or totalOnes>3)
                board[ind][jnd] = 3;
        } else {
            if(totalOnes==3) board[ind][jnd] = -1; // if 3 neighbour make it live
            else return;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                helper(board, i, j);
            }
        }
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]==3) {
                    board[i][j]=0;
                } else if(board[i][j]==-1) {
                    board[i][j]=1;
                }
            }
        }
    }
};