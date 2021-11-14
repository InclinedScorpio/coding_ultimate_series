// https://leetcode.com/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string command) {
        string res="";
        for(int i=0;i<command.length();) {
            if(command[i]=='G') {
                res+="G";
                i+=1;
            }else if(command[i]=='('&&command[i+1]==')') {
                res+="o";
                i+=2;
            }else {
                res+="al";
                i+=4;
            }
        }
        return res;
    }
};