// https://leetcode.com/problems/the-kth-factor-of-n/

/**
 * LOGIC: basic question!
 * 
 */ 
class Solution {
public:
    int kthFactor(int n, int k) {
        int currFactors=1;
        if(k==1) return 1;
        if(n%2==0) currFactors++;
        if(k==currFactors) return 2;
        
        for(int i=3;i<=n;i++) {
            if(n%i==0) {
                currFactors++;
            }
            if(currFactors==k) {
                return i;   
            }
        }
        return -1;
    }
};