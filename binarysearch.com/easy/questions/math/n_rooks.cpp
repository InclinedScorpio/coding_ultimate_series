// https://binarysearch.com/problems/N-Rooks

int solve(int n) {
    int ind=1;
    for(int i=1;i<=n;ind = i*ind, i++);
    return ind;
}