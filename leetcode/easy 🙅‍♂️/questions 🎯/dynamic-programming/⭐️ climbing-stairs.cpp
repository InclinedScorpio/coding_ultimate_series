// https://leetcode.com/problems/climbing-stairs/

/**
 * HINT: The sequence we get after checking n's value from 1.5 is basically fibonacci
 * Hence, the question was asking to indirect implement fibonacci
 * 
 */ 
class Solution {
public:
    int climbStairs(int n) {
        int first = 0;
        int second = 1;
        while(n-->0) {
            int temp = second;
            second = first + second;
            first = temp;
        }
        return second;
    }
};