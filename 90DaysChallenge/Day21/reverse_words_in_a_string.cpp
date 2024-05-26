// https://leetcode.com/problems/reverse-words-in-a-string

/**
 * Problem requires understanding of pointers
*/
class Solution {
public:
    void reverseCurrWork(string& s, int ind) {
        int saveInd = ind;
        string str = "";
        while(ind<s.length() && s[ind]!=' ') {
            str = str + s[ind++];
        }
        ind = str.length()-1;
        while(ind>=0) {
            s[saveInd] = str[ind];
            saveInd++;
            ind--;
        }
    }

    string reverseWords(string s) {
        for(int i=0;i<s.length();i++) {
            if(i==0 && s[i]!=' ') {
                reverseCurrWork(s, 0);
            }
            if(i>0 && s[i]!=' ' && s[i-1]==' ') {
                reverseCurrWork(s, i);
            }
        }
        int starting = 0, ending=s.length();
        int ind = 0;
        while(s.length()>0 && s[ind]==' ') {
            starting++;
            ind++;
        }
        ind = s.length()-1;
        while(s.length()>0 && s[ind]==' ') {
            ending--;
            ind--;
        }
        string newStr = "";
        for(int i=starting;i<ending;i++) {
            if(i>starting && s[i]==' ' && s[i-1]==' ') {
                continue;
            }
            newStr = newStr + s[i];
        }
        for(int i=0, j=newStr.length()-1;i<newStr.length()/2;i++, j--) {
            char temp = newStr[i];
            newStr[i] = newStr[j];
            newStr[j] = temp;
        }
        return newStr;
    }
};