// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int isNeg=1;
        if(x<0) isNeg=-1;
        string str = to_string(x);
        ::reverse(str.begin(), str.end());
        try {
            return isNeg * stoi(str);    
        } catch (...){
            return 0;
        }
    }
};