// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        int fir = 0, sec=1;
        while(n--) {
            int thir = fir+sec;
            fir = sec;
            sec = thir;
        }
        return fir;
    }
};