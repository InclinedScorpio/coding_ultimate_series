// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        
        // bianry search
        long long int low = 0;
        long long int high = x;
        long long int mid;
        while(low<=high) {
            mid = (low+high)/2;
            long long int sq = mid*mid;
            if(sq==x) {
                return mid;
            }
            
            if(sq>x) {
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        
        // covering edge condition - if sq is coming more than x, take 1 less
        if(mid*mid>x) {
            return mid-1;
        }
        int result = mid;
        return result;
    }
};