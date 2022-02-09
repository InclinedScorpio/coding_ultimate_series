// https://binarysearch.com/problems/Number-of-Bits

int solve(int n) {
    int res=0;
    while(n) {
        if(n%2==1) res++;
        n=n/2;
    }
    return res;
}