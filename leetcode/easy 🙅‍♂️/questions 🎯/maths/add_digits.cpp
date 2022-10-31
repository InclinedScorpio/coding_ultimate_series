// https://leetcode.com/problems/add-digits/

/**
 * LOGIC: Basic problem
 * 
 */ 
class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0; 
        int sum=0;
        while(num) {
            int sum=0;
            while(num) {
                sum+=num%10;
                num/=10;
            }
            num = sum;
            if(to_string(num).length()==1) return num;
        }
        return 0;
    }
};