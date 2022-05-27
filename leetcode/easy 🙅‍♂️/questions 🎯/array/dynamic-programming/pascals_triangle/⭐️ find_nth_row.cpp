
/**
 * QUESTION: Find nth row of Pascals Triangle
 * LOGIC: Can be found by doing nCr
 * - nCr represents nth row, rth column of Pascals Triangle
 * 
 * COMPLEXITY: O(rows * rows)
 * SPACE: O(N)
 * 
 * Can we optimise time complexity ? As we know it's nCr and it's like 3c1, 3c2.. pattern ?
 * YES!
 * 
 */ 
#include<iostream>
#include<vector>

using namespace std;

int fact(int n) {
    if(n==1 || n==0) return 1;
    return n * fact(n-1);
}

// nCr to find item present in Pascals triangle at n,r
int nCr(int n, int r) {
    return fact(n)/(fact(r)*fact(n-r));
}

int main() {
    int row=5;
    
    vector<int> res(row, 1);

    for(int i=1;i<row-1;i++) {
        res[i] = nCr(row-1, i);
    }

    //print
    for(int i=0;i<row;i++) {
        cout<<res[i]<<" ";
    }
}