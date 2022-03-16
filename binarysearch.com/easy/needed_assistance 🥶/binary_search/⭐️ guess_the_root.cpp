// https://binarysearch.com/problems/Guess-the-Root

/**
 * LOGIC: Just to identify it's a Binary Search problem
 * 
 */ 
int solve(int n) {
    long long int left=1, right=n;
    while(left<=right) {
        long long int mid = (left+right)/2;
        if(mid*mid == n) return mid;
        if(mid*mid < n) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}
