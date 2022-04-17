/**
QUESTION: Rat in a Maze
You are given a an integer N and a grid of size NxN. The cells of the grid are numbered row wise from 1 to N^2. Rat wants to travel from cell number 1 to cell number N^2, and it can move in only right direction or down direction from a particular cell. There is exactly one path from source to destination as some cells are blocked. Help the rat to find the path.

Input Format:
In the function an integer N is given, and a 2D vector consisting of only 'O's And 'X's is given where 'X' represents blocked cell.

Output Format:
Return a vector of cell numbers of cells in path (in sequence).

Sample Testcase:

Input:
4

O O X O
O X O O
O O O X
X X O O

Output:
1  5  9  10  11  15  16

Explanation:
The only path is 1 5 9 10 11 15 16.
**/

/**
 * LOGIC: At each grid we have 2 choices
 * - Either go right, or go bottom...
 * - if from right or bottom, out of bounds, just return back
 * - If grid is blocker -> 'X' then also return back
 * - If both right and bottom are not possible -> return back!
 * 
 * - This can be achived through recursion...
 * - As at each point we have predefined set of operations which we can try!
 * 
 * COMPLEXITY: O(2^(n^2))
 * How? At each grid we have can make 2 decisions, 
 * & number of grids are n^2 so time complexity gets 2^(n*n)
 **/

#include<bits/stdc++.h>
using namespace std;

struct Result { 
    bool isSolution;
    vector<int> store;  
};

int calGrid(int i, int j, int n) {
    return (i*n) + (j+1);
}

Result findingPath(vector<vector<char>> maze, int i, int j, Result store) {
    if(i==((int)maze.size()-1) && j==((int)maze[i].size()-1)) {
        store.isSolution = true;
        store.store.push_back(calGrid(i, j, maze.size()));
        return store;
    }
    
    // if rows or column exceed, we can't go here
    if(i>=(int)maze.size() || j>=(int)maze[i].size()) {
        store.isSolution=false;
        return store;
    }
    
    if(maze[i][j]=='X') {
        store.isSolution = false;
        return store;
    }
    
    // it's 0
    store.store.push_back(calGrid(i, j, maze.size()));
    Result res = findingPath(maze, i, j+1, store);
    if(res.isSolution) {
        return res;
    }
    res = findingPath(maze, i+1, j, store);
    if(res.isSolution) {
        return res;
    }
    store.store.pop_back();
    store.isSolution = false;
    return store;
}

vector<int> findPath(int n, vector<vector<char>> c){
    return findingPath(c, 0, 0, {true, {}}).store;
}