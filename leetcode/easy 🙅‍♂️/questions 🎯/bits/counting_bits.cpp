// https://leetcode.com/problems/counting-bits/

/**
 * LOGIC: Basic problem!
 *
 */
class Solution {
public:
    int checkOnes(int n) {
        int totalOnes=0;
        while(n) {
            if(n%2!=0) totalOnes++;
            n = n/2;
        }
        return totalOnes;
    }
    
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++) {
            result.push_back(checkOnes(i));
        }
        return result;
    }
};