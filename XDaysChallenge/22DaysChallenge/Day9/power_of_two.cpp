// https://leetcode.com/problems/power-of-two/description/

/**
 * Question requires only understanding of recursion.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==0 || n%2!=0) return false;
        return isPowerOfTwo(n/2);
    }
};