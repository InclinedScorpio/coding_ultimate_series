// https://binarysearch.com/problems/Repeated-Addition

int solve(int n) {
    int len=to_string(n).length();
    long long int sum=0;
    while(true) {
        if(n<10) {
            return n;
        }
        sum=0;
        while(n) {
            sum= sum + n%10;
            n=n/10;
        }
        n=sum;
    }
}
