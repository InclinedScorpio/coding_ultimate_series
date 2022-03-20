// https://leetcode.com/problems/integer-to-roman/

/**
 * LOGIC: Logic is to create the hash table considering appropriate exceptions for roman
 * - Exceptions are already given in question like IV is 4 ('I' is small and still coming before 'V'- that's why exception)
 * - Once hash table is created just, just run the loop to create the roman numeral
 * 
 */ 
class Solution {
public:
    string intToRoman(int num) {
        string ch[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        
        int ind=(sizeof(ch)/sizeof(ch[0]))-1;
        string result = "";
        while(num>0) {
            int currentVal = nums[ind];
            while((num-currentVal)>=0) {
                result+=ch[ind];
                num-=currentVal;
            }
            ind--;
        }
        return result;
    }
};