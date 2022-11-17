// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    string findBinary(int num) {
        string str="";
        while(num) {
            str = to_string(num%2) + str;
            num = num/2;
        }
        return str;
    }
    
    int hammingDistance(int x, int y) {
        string xStr = findBinary(x);
        string yStr = findBinary(y);
        int diff=max(xStr.length(), yStr.length()) - min(xStr.length(), yStr.length());
        
        if(xStr.length()>yStr.length()) 
            while(diff--) yStr="0"+yStr;
        
        if(xStr.length()<yStr.length()) 
            while(diff--) xStr="0"+xStr;

        int count=0;
        for(int i=0;i<xStr.length();i++) {
            if(xStr[i]!=yStr[i]) {
                count++;
            }
        }
        return count;
    }
};