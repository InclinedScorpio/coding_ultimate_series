// https://binarysearch.com/problems/Prime-Factorization

#include <iostream>
#include<math.h>
using namespace std;
 
/**
 * QUESTION: Find prime numbers
 * 1. Exhaust 2's first (only even prime)
 * 2. Exhaust 3,5,7,9,11,13... sqrt(n) - (works as if 3 is done, 9, 18 won't divide)
 * 3. At last one number may remain (which would be a prime no. >sqrt(n)) - directly print it
 * 
 * COMPLEXITY: O(√n * logN)
 * √n - is because of pow(n,0.5)
 * logN - is because of n=n/i
 */ 
void primeFactors(int n)
{
    //1.
    while(n%2==0) {
        cout<<2<<" ";
        n/=2;
    }

    // 2. even exhausted, odd remained
    for(int i=3;i<pow(n, 0.5);i=i+2) {
        while(n%i==0) {
            cout<<i<<" ";
            n/=i;
        }
        if(i>n) { // if i got > n - no use of going forward
            cout<<endl<<" breaked "<<i<<" n:"<<n<<endl;
            break;
        }
    }
    
    //3.
    if(n>1) cout<<" | one left over > sqrt(n): "<<n;
}
 // 2, 3, 5, 7, 11, 13
/* Driver code */
int main()
{
    int n = 243;//10,000 
    primeFactors(n);
    return 0;
}
 