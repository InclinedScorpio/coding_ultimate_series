// https://binarysearch.com/problems/Nth-Fibonacci-Number

int solve(int n) {
    int left=1, right=1, curr=left;
    for(int i=3;i<=n;i++) {
        curr = left + right;
        left = right;
        right = curr;
    }
    return curr;
}