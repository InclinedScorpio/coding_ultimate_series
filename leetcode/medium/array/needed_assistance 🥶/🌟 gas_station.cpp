// https://leetcode.com/problems/gas-station/

/**
 * LOGIC: Brute force is easy, thinking about optimization is tedious part
 * - Yet, it's easy to think about the optimization part.
 * - As on reaching each station, we can refill the gas, and the amount of gas required to travel will be substracted
 * - Let's say the man travelled from index 3 to 7 and on 7 he had no more gas.
 * - So, even if you start from 4-6, still the man won't go beyond 7, let alone the complete cycle...
 * - But why? - because at each station we WILL HAVE 0 or more in surplus and if that couldn't help him go over 7 how will individual gas will help
 * COMPLEXITY: O(N)
 */
class Solution {
public:
    int checkPossible(vector<int>& gas, vector<int>& cost, int ind, int initialSize) {
        int currentGas = gas[ind];
        for(int i=ind+1;i<=(ind+initialSize);i++) {
            if(currentGas<cost[(i-1)%initialSize] || currentGas==0) return i;
            currentGas+=gas[(i%initialSize)];
            currentGas-=cost[(i-1)%initialSize];
        }
        return -1;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int initialSize = gas.size();
        
        for(int i=0;i<initialSize;i++) {
            int ind = checkPossible(gas, cost, i, initialSize);
            if(ind==-1) return i;
            if(ind<i) return -1;
            else i = ind-1;
        }
        return -1;
    }
};
