/**
QUESTION: **Game of Coins**

Oswald and Henry are playing the game of coins. They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn] where Ci coin has Vi value. They take turns alternatively. In one turn the player can pick either the first or the last coin of the row. Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.

Input Format:

In the function you are given an integer N i.e. the number of coins and a vector V which represents the values of each coin in the row respectively.

Output Format:

Return a single integer which is the maximum possible value as asked in the question.

Constraints:

1<=N<=15

1<=V[i]<=1000

Sample Testcase:

Input:

4

1 2 3 4

Output:

6

Explanation:

Oswald will pick up coin with value 4, Henry will pick coin with value 3, Oswald will pick 2 and Henry will pick 1. Hence 4+2=6.
**/

/**
 * 
 * LOGIC: At each point we have 2 decisions to make either first, or last one
 * - And result could come from either of them,
 * - Hence, clear case of recursion! We can take both of them and pick the greater one!
 * 
 * COMPLEXITY: O(2N)
 */ 


#include <bits/stdc++.h>
using namespace std;

int calculateMax(vector<int> v, int i, int j, int sum, bool henry) {
    if(i>j) {
        return sum;
    }
    if(henry) {
        int left = calculateMax(v, i+1, j, sum+v[i], false);
        int right = calculateMax(v, i, j-1, sum+v[j], false);
        return max(left, right);
    } else {
        if(v[i]>v[j]) {
            return calculateMax(v, i+1, j, sum, true);
        } else {
            return calculateMax(v, i, j-1, sum, true);
        }
    }
}

int MaxValue(int n, vector<int> v){
    return calculateMax(v, 0, n-1, 0, true);
}
