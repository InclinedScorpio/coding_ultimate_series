/**

QUESTION: Longest Possible Route

Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of longest possible route possible from top left position (0,0) to bottom right position (m,n)  within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contains any diagonal moves and a location once visited in a particular path cannot be visited again.

Input Format:
In the function you are given number of rows M, number of columns N and 2D vector (M X N) consisting of 0s and 1s where 0s represents the hurdles.

Output Format:
A single integer representing the length of longest path.

Constraints:
1<=M,N<=10

Sample Testcase:

Input:
3 3

1 1 1
1 1 1
0 0 1

Output:
6

Explanation:
Here the longest possible path has a path length of 6.
**/

/**
 * LOGIC: At each grid we have 4 choices to go
 * - Top, left, right, bottom
 * - Hence, as we have predefined ways to go- we can simply use recursion
 * 
 * - Problem similar to Rat-Maze & N-Queens!
 * 
 * NOTE:
 * 1) Here we can't visit already visited grid, so we will keep 0 which we have visited (1 means path)
 * 2) ... and once the solutions through that path is completed we can place 1 back (backtracking)
 * 3) After each unsuccessful path find, we will backtrack and search for some other path!
 * 
 * COMPLEXITY: O(4^(N^2))
 * 
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct Result {
    bool isSolution;
    int total;
};

Result findLongPath(vector<vector<int>> path, int i, int j, Result res) {
    // bound exceed
    if(i>=(int)path.size() || j>=(int)path[i].size() || i<0 || j<0) {
        res.isSolution = false;
        return res;
    }
    
    // no path - it's not 1
    if(path[i][j]!=1) {
        res.isSolution = false;
        return res;
    }
    
    // reached destination
    if(i==(int)path.size()-1 && j==(int)path[path.size()-1].size()-1) {
        // res.total+=1;
        res.isSolution=true;
        return res;
    }
    
    path[i][j]=0; // marking reached, so can't go back here
    
    // logic! - go left, right, bottom
    res.total+=1;
    cout<<endl<<i<<" | "<<j<<endl;
    Result leftRes = findLongPath(path, i, j-1, res);
    Result bottomRes = findLongPath(path, i+1, j, res);
    Result rightRes = findLongPath(path, i, j+1, res);
    Result topRes = findLongPath(path, i-1, j, res);
    
    int currMax=res.total;
    res.isSolution=false;
    if(leftRes.isSolution) {
        currMax = max(currMax, leftRes.total);
        res.isSolution=true;
    }
    if(bottomRes.isSolution) {
        currMax = max(currMax, bottomRes.total);
        res.isSolution=true;
    }
    if(rightRes.isSolution) {
        currMax = max(currMax, rightRes.total);
        res.isSolution=true;
    }
    if(topRes.isSolution) {
        currMax = max(currMax, topRes.total);
        res.isSolution=true;
    }
    res.total = currMax;
    path[i][j]=1; // turn it back to 1 as we are done
    return res;
}

int main(){
    vector<vector<int>> v = {
        {1,1,1,1},
        {1,1,0,1},
        {0,0,0,1}
    };
    int ss =  findLongPath(v, 0, 0, {false, 0}).total;
    cout<<ss;
}
