/**
 * 
 * QUESTION: Find nth row of Pascals Triangle
 * LOGIC: As we see there is a pattern nCr, nCr-1, nCr-2....
 * We clearly see that we are multiplying some number at both num/denominator
 * - Hence we can make use of it to find nth row in linear time complexity
 * 
 * COMPLEXITY: O(row)
 * SPACE: O (row)
 * 
 */ 
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int row=5;
    
    vector<int> res(row, 1);

    for(int i=1;i<row-1;i++) {
        res[i] = res[i-1]* (((row-1) - (i-1))/(float)i);
    }

    //print
    for(int i=0;i<row;i++) {
        cout<<res[i]<<" ";
    }
}