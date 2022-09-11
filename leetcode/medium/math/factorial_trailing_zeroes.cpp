// https://leetcode.com/problems/factorial-trailing-zeroes/

/**
 * LOGIC: Just check how many factors of 5 are present and return them
 * - Reason - 5 along with any number will give birth to a 0 ( 5 x 2 = 10 -> '0')
 *
 */
class Solution {
public:
    int trailingZeroes(int n) {
        // just count 5's multiples
        
        int fivesMultiple=0;
        while((n/5)>0) {
            fivesMultiple += n/5;
            n=n/5;
        }
        return fivesMultiple;
    }
};