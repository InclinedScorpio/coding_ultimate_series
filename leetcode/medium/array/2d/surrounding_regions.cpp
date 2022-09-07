// https://leetcode.com/problems/surrounded-regions/

/**
 * LOGIC: Point is to understand the question. It's asked to block all the 0's which are along with border
 * - Hence first we block the 0's which are along the border, then we replace the remaining 0's with X
 *
 */
class Solution {
public:
    void blockZeroes(vector<vector<char>>& board, int ind, int jnd) {
        if(ind<0 || jnd<0 || ind>=board.size() || jnd>=board[ind].size()) {
            return;
        }
        // cout<<ind<<" "<<jnd<<endl;
        if(board[ind][jnd]=='X' || board[ind][jnd]=='$') return;
        // cout<<ind<<" "<<jnd<<endl;
        board[ind][jnd]='$';
        blockZeroes(board, ind+1, jnd);
        blockZeroes(board, ind-1, jnd);
        blockZeroes(board, ind, jnd-1);
        blockZeroes(board, ind, jnd+1);
    }
    
    void solve(vector<vector<char>>& board) {
        // block top and last row
        for(int i=0;i<board[0].size();i++) {
            if(board[0][i]=='O') {
                cout<<0<<" | "<<i<<endl;
                blockZeroes(board, 0, i);
            }
            
            if(board[board.size()-1][i]=='O') {
                cout<<board.size()-1<<" | "<<i<<endl;
                blockZeroes(board, board.size()-1, i);
            }
        }
        
        // block first and last col
        for(int i=0;i<board.size();i++) {
            if(board[i][0]=='O') {
                blockZeroes(board, i, 0);
            }
            
            if(board[i][board[0].size()-1]=='O') {
                blockZeroes(board, i, board[0].size()-1);
            }
        }
        
        // replace remaining 0 with X
        for(int i=1;i<board.size()-1;i++) {
            for(int j=1;j<board[i].size()-1;j++) {
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        
        // replace remaining $ with 0
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]=='$') board[i][j]='O';
            }
        }
    }
};