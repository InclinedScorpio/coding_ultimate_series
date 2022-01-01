// https://leetcode.com/problems/roman-to-integer/

/***
 * Seems tedious- it's just if/else statements!
 * 
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
 * Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
 * The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 * 
 * Example 1:
 *
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 */ 

class Solution {
public:
    int romanToInt(string s) {
        int lastIndex = s.length();
        int totalSum=0;
        
        for(int i=0;i<s.length();i++) {

            if(s[i]=='I'){
                bool isDecreasing = false;
                if(i!=lastIndex) {
                    if(s[i+1]=='V') {
                        totalSum+=4;
                        i++;
                        isDecreasing = true;
                    }
                    if(s[i+1]=='X') {
                        totalSum+=9;
                        i++;
                        isDecreasing = true;
                    }
                    if(!isDecreasing) {
                        totalSum+=1;
                    }
                } else {
                    totalSum+=1;
                }
            } else if(s[i]=='X'){
                bool isDecreasing = false;
                if(i!=lastIndex) {
                    if(s[i+1]=='L') {
                        totalSum+=40;
                        i++;
                        isDecreasing = true;
                    }
                    if(s[i+1]=='C') {
                        totalSum+=90;
                        i++;
                        isDecreasing = true;
                    }
                    if(!isDecreasing) {
                        totalSum+=10;
                    }
                } else {
                    totalSum+=10;
                }
            } else if(s[i]=='C'){
                bool isDecreasing = false;
                if(i!=lastIndex) {
                    if(s[i+1]=='D') {
                        totalSum+=400;
                        i++;
                        isDecreasing = true;
                    }
                    if(s[i+1]=='M') {
                        totalSum+=900;
                        i++;
                        isDecreasing = true;
                    }
                    if(!isDecreasing) {
                        totalSum+=100;
                    }
                } else {
                    totalSum+=100;
                }
            } else if (s[i]=='V') {
                totalSum+=5;
            } else if (s[i]=='L') {
                totalSum+=50;
            } else if (s[i]=='D') {
                totalSum+=500;
            } else if (s[i]=='M') {
                totalSum+=1000;
            }  
            
        }
        
        return totalSum;
        
    }
};