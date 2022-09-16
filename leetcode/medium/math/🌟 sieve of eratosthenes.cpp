

/**
 * LOGIC: Tricky question, make sure to do it onces
 * - Just apply maths
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        
        int totalNonPrimes=1;
        vector<int> marker(n, 0);
        
        for(int i=2;i*i<n;i++) {  // trick (1) - no need to goto n, just goto root n as for every num before i*(1..2..3..i-1), till i-1 must have been already covered
            long long int j=i*2;  // (2) - mark all multiples of that num
            if(marker[i]==0) {
                while(j<n) {
                    if(marker[j]==0) {
                        marker[j]=1;
                        totalNonPrimes++;
                    }
                    j+=i;
                }
            }
        }
        return (n-1) - totalNonPrimes;  // no need to run separate loop for counting the primes
    }
};