/**
 * QUESTION: Find Nsqrt{M}
 * - We can see answer would definitely lie btw 1 and M
 * - Hence, it's a Monotonic binary search question
 * 
 * - The POINT TO NOTE! is we shall stop when difference btw left and right is less than 10^-6
 * - That is because we will get answer in double
 * 
 * COMPLEXITY: O(logK * logM^(10^6))
 * - 10^6 is because we are taking difference upto 1e-6 and hence there will be 10^6 digits in btw 
 * 
 */ 
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

double findNRootM(int n, int m) {
    double diff = 1e-6;
    double left = 1.0, right = m;
    while((right-left) > diff) {
        double mid = (right+left)/2.0;
        double midPowerN = pow(mid, n);
        if(midPowerN==m) return mid;
        if(midPowerN > m) {
            right=mid;
        } else {
            left=mid;
        }
    }
    return (right+left)/2.0;
}

int main() {
    int n=3;
    int m=30;
    // 3(root 27)

    cout<<findNRootM(n,m);
    cout<<endl<<"Confirming result below ....."<<endl;
    cout<<pow(m, (double)(1.0/(double)3.0));
}
