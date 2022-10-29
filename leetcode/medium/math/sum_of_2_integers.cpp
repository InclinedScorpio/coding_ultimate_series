// https://leetcode.com/problems/sum-of-two-integers/

/**
 * LOGIC: Point is not to use +, or -
 * - Here we will manually increase the number
 * - Make sure to take care of negative values
 */
class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            if(a<=0 && b<=0) {
                a--;
                b++;
            } else if(a<=0 && b>=0) {
                a++;
                b--;
            } else if(a>=0 && b<=0) {
                a--;
                b++; 
            } else {
                a++;
                b--;
            }
        }
        return a;
    }
};