// https://binarysearch.com/problems/Perfect-Squares


/**
 * LOGIC: Question is of maths, but of dp! (It's little clear after reading qustion that recursion has to be done)
 * - As there were many ways we could have done hence recursion was the thing to do
 * - Also while doing recursion - we found overlapping subproblems
 * - Hence do memoization!
 * 
 * COMPLEXITY: O(N Root(N))
 * 
 */ 
int helper(int n, vector<int>& isVisited) {
    if(n<=3) return n;
    if(isVisited[n]!=0) return isVisited[n];
    int minVal = INT_MAX;
    for(int i=1;i<=n;i++) {
        if(i*i>n) break;
        if(i*i==n) {
            isVisited[n] = 1;
            return 1;
        };
        if((n - (i*i))>0) {
            minVal = min(minVal, helper(n - (i*i), isVisited));
        }
    }
    return isVisited[n] = minVal+1;
}

int solve(int n) {
    vector<int> isVisited(n+1);
    return helper(n, isVisited);
}