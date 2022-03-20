// https://binarysearch.com/problems/A-Flight-of-Stairs

/**
 * LOGIC: Point is to understand question is basically Fibonnaci series
 * Other point to understand is, for each iteration we need to do the Mod
 * as for higher inputs eg. N=415, result will be 10^80
 * - Hence we need to keep doing Mod, rather than doing mod at the last!
 * 
 */ 
int solve(int n) {
    unsigned long long int left=1;
    unsigned long long int right=1;
    for(long long int i=1;i<=n;i++) {
        long long int saveRight=right;
        unsigned long long int modBy = pow(10, 9)+7;
        right = (left+right)%modBy;
        left = saveRight;
    }
    return left;
}