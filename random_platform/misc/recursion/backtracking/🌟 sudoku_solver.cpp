/**
 * QUESTION: Complete the given Sudoku Puzzle!
 * 
 * LOGIC: At each grid we are required to fill data from 1-9
 * - each '0' grid can have data from 1-9 but as per condition
 * - What if we check 1st grid condition and see what can be entered from 1-9
 * - And move on with next column/row grid present to fill there data as well ?
 * 
 * - What if nothing from 1-9 can be entered?? Then backtrack
 * - And change data in previous grid. Once updated, again call next grid
 * - Recurse & Backtrack
 * 
 * COMPLEXITY: What's complexity of 2 grid? _ _ (it's 9x9 = 81)
 * - So for a grid with NxN, it would be 9^(N^2)
 * 
 */
#include<iostream>
#include<vector>

using namespace std;

void printSudoku(vector<vector<int> > sudoku) {
    for(int i=0;i<sudoku.size();i++) {
        for(int j=0;j<sudoku[i].size();j++) {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkNumPossible(vector<vector<int> > sudoku, int row, int column, int num) {
    // check row
    for(int j=0;j<sudoku[row].size();j++) {
        if(sudoku[row][j]==num) return false;
    }

    // check column
    for(int i=0;i<sudoku.size();i++) {
        if(sudoku[i][column]==num) return false;
    }
    
    // check grid
    int i=(row/3)*3, j=(column/3)*3;  // NOTE! Make sure to Multiply by 3 !
    for(int r=i;r<i+3;r++) {
        for(int c=j;c<j+3;c++) {
            if(sudoku[r][c]==num) return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int> > sudoku, int row=0, int column=0) {
    if(row>=sudoku.size()) {
        printSudoku(sudoku);
        return true;
    }

    // at column end, take it to next row starting
    if(column==sudoku[row].size()) {
        return sudokuSolver(sudoku, row+1, 0);
    }

    // already filled grid
    if(sudoku[row][column]!=0) {
        return sudokuSolver(sudoku, row, column+1);
    }
    
    for(int i=1;i<=9;i++) {
        if(checkNumPossible(sudoku, row, column, i)) {
            sudoku[row][column]=i;
            bool isNumInserted = sudokuSolver(sudoku, row, column+1);
            if(isNumInserted) return true;
            sudoku[row][column]=0;
        }
    }
    return false;
}

int main() {
    vector<vector<int> > sudoku = 
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudokuSolver(sudoku);
}
