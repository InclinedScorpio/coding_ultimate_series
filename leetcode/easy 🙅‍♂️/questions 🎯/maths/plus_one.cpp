// https://leetcode.com/problems/plus-one/

// basic problem
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        cout<<digits[digits.size()-1];
        int carry=1;
        int sum=0;
        for(int i=digits.size()-1;i>=0;i--) { 
            int currNum = digits[i];
            if(currNum==9 && carry) {
                currNum=0;
                carry=1;
            } else if(carry) {
                currNum++;
                carry=0;
            }
            digits[i] = currNum;
        }
        if(carry) 
            digits.insert(digits.begin()+0, 1);
        return digits;
    }
};