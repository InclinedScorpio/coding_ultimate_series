/**
 * LOGIC: If you take 2x3 grid then the possible values to reach end is
 * RRD
 * DRR
 * RDR..
 * 
 * - Hence we understand that 2R and 1D must be there wherever it comes
 * So for larger NxM also it will work
 * 
 * - Hence, first check how many blanks will be there
 * (n-1) + (m-1)
 * 
 * - Now, TotC(n-1) or TotC(m-1) anyone of them will work
 * - This is solution using combination
 * 
 * COMPLEXITY: O(N)
 * 
 * 
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalBlanks=(m + n - 2);
        int minDist = m - 1;
        double res=1;
        for(int i=1;i<=minDist;i++) {
            res = res * (totalBlanks-minDist+i)/i; // this line created problem before while trying 'totalBlanks--'
        }
        return (int)res;
    }
};