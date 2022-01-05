// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int lastOneLength = 0;
        bool stringStarted = false;
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i]==' ' && !stringStarted) {
                continue;
            }
            stringStarted = true;
            
            if(s[i]==' ') {
                return lastOneLength;
            }
            lastOneLength++;
        }
        return lastOneLength;
        
    }
};