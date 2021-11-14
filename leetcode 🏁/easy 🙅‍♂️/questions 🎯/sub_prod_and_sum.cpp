// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int sum=0;
        int mul=1;
        while(n!=0) {
            int temp = n%10;
            sum+=temp;
            mul*=temp;
            n/=10;
        }
        return mul-sum;
        
    }
};