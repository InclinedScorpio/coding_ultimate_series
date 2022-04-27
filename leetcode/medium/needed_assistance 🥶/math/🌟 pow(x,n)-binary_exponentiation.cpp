// https://leetcode.com/problems/powx-n/

/**
 * LOGIC: We need to reduce complexity from O(n) to O(logN)
 * - Let's say we need to calculate 4^10
 * - Now we can do 4 x 4 x 4 x 4 x 4... (10 times)
 * - How to reduce it?
 * - We can do (4^2)^5
 * - We just half the power! and (4^2) = 4 x 4 -> 1unit
 * - Now power is 5 so we do 16 * (16)^4
 * - As power is even again half it -> 16 * (256)^2
 * - That's how we will keep doing half the power
 * 
 * COMPLEXITY: O(logN)- how? We keep doing power half - & that's the number of steps
 * 
 */ 
class Solution {
public:
    double calPow(double x, long n) {
        if(n<=0) return 1;
        if(n%2==0) {
            x = x*x;
            return calPow(x, n/2);
        } else {
            return x * calPow(x, n-1);
        }
    }
    
    double myPow(double x, int n) {
        long power = abs(n);
        double result = calPow(x, power);
        if(n<0) {
            return 1/result;
        }
        return result;
    }
};