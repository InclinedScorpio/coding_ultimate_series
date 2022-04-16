/**
 * QUESTIONS: Place N Queens on the board, so no one cuts each other
 * LOGIC: Logic is simple
 * - Think just like how you would think in reality
 * - Will place queen at first grid... & first row gets locked (as queen will cancel)
 * - Now check 2nd row, where queen can be placed
 * - In third row, if queen can't be placed anywhere then backtrack and move forward queen as the position of 2nd row queen is not feasible
 * - Now again come to 3rd row and keep working towards the last row
 * - Once done, print and return true so all row knows it's done!
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 

#include <iostream>
#include <vector>

using namespace std;

bool checkQueenBePlaced(vector<vector<int> > board, int row, int column) {
    // check column
    for(int i=0;i<=row;i++) {
        if(board[i][column]) return false;
    }

    // check left-upper diagonal
    int i=row-1, j=column-1;
    while(i>=0 && j>=0) {
        if(board[i][j]==1) return false;
        i--;j--;
    }

    // check right-upper diagonal
    i=row-1, j=column+1;
    while(i>=0 && j<board[i].size()) {
        if(board[i][j]==1) return false;
        i--;j++;
    }
    
    // can be placed
    return true;
}

void printBoard(vector<vector<int> > board) {
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool nQueensProblem(vector<vector<int> > board, int numberOfQueens, int currRow) {
    if(currRow >= board.size() || numberOfQueens==0) {
        printBoard(board);
        return true;
    }

    for(int j=0;j<board[currRow].size();j++) {
        if(checkQueenBePlaced(board, currRow, j)) {
            // can be placed
            board[currRow][j]=1;
            bool isPlaced = nQueensProblem(board, numberOfQueens-1, currRow+1);
            if(isPlaced) return true;
            board[currRow][j]=0;
        }
    }
    return false;
}

int main() {
    int boardSize=3;
    int numberOfQueens=2;
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));
    nQueensProblem(board, numberOfQueens, 0);
}
