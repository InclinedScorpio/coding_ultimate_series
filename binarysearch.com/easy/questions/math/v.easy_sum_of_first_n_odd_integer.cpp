// https://binarysearch.com/problems/Sum-of-First-N-Odd-Integers

int solve(int n) {
    int count=0;
    int ind=1;
    int sum=0;
    while(count!=n) {
        sum+=ind;
        ind+=2;
        count++;
    }
    return sum;
}