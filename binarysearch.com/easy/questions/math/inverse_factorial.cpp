// https://binarysearch.com/problems/Inverse-Factorial

int solve(int a) {
    int sum=1;
    int index;
    for(int i=1;sum<a;i++) {
        sum=sum*i;
        index=i;
    }
    if(sum==a) return index;
    return -1;
}
