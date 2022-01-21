// https://leetcode.com/problems/number-of-1-bits/
 
/**
 * LOGIC: Remember uint_t32 is a no. of 32 digits
 * So if it's 1 i.e 00000... <31>....1
 * 
 * - uint32_t is basically a typedef for unsigned int, (0-2^32)
 */ 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int countOnes = 0;
        while(n) {
            n%2==1 ? countOnes++ : 0;
            n/=2;
        }
        return countOnes;
    }
};