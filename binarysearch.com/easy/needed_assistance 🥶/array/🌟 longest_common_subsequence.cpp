// https://binarysearch.com/problems/Longest-Common-Subsequence

/**
 * LOGIC: String subsequence is a well known DP problem
 * - Main logic are:
 * 1. Keep both string as the x and y axis of 2D matrix
 * 2. At every point we need to check some things
 * 2.1. If char are equal - just pick i-1, j-1 why?
 * ... because that will give max subsequence at that point when curr char was not part of string
 * 2.2. If it's not equal - check top or previous why>
 * ... because top tells us the max when curr char was not taken
 * ... and previous tells when curr Char was taken but matching strings curr char (top x) was not taken
 * ... The max is kept as final answer in each index
 * 
 * - So at each index, the max value gets placed Thanks to 2.1. for incrementing the count
 * - And 2.2. for picking the max if char are not equal
 * - So, the last index will return back the answer
 * 
 * COMPLEXITY: O(N*M)
 * 
 */ 
int solve(string a, string b) {
    if(a.length()==0 || b.length()==0) return 0;

    vector<vector<int> > store(a.length(), vector<int>(b.length()));

    int leftToRight = 0, topToBottom=0;
    for(int i=0;i<a.length();i++) {
        if(topToBottom || b[0]==a[i]) {
            store[i][0]=1;
            topToBottom=1;
        }
    }

    leftToRight=store[0][0];
    for(int j=0;j<b.length();j++) {
        if(leftToRight || b[j]==a[0]) {
            store[0][j]=1;
            leftToRight=1;
        }
    }

    bool pickCurrent = true;

    for(int i=1;i<a.length();i++) {
        for(int j=1;j<b.length();j++) {
            if(a[i]==b[j]) {
                pickCurrent = false;
                store[i][j] = store[i-1][j-1] + 1;
            } else {
                store[i][j] = max(store[i-1][j], store[i][j-1]);
            }
        }
    }

    return store[a.length()-1][b.length()-1];
}