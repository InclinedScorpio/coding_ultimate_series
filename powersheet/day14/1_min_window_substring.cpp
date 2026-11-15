// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    Solution() {
        this->tLen=0;
    }
    
    unordered_map<char, int> counter; //t
    unordered_map<char, int> checker; // curr
    int tLen;


    void changeChar(string& s, int ind, bool toAdd) {
        // add
        if(counter.find(s[ind])!=counter.end()) {
            // exists in counter
            if(checker.find(s[ind])!=checker.end()) {
                // exists in checker as well
                if(toAdd) {
                    if(counter[s[ind]]>checker[s[ind]]) {
                        tLen++;
                    }
                    checker[s[ind]]++;
                } else {
                    if(counter[s[ind]]>=checker[s[ind]]) {
                        tLen--;
                    }
                    checker[s[ind]]--;
                }
            } else {
                checker[s[ind]]=1;
                tLen++;
            }
        }
    }




    string minWindow(string s, string t) {
        for(char ti: t) {
            counter[ti]++;
        }
        int left=0, right=0;
        int minFound=INT_MAX;
        string res="";

        int start=-1, pick=-1;

        while(right<s.length()) {
            // cover the t
            this->changeChar(s, right, true);

            while(tLen==t.length()) {
                if((right-left+1)<minFound) {
                    minFound=right-left+1;
                    start=left;
                    pick = right-left+1;
                }
                // take left forward until complete tLen reduces
                this->changeChar(s, left, false);
                left++;
            }
            right++;
        }
        return start==-1 ? "": s.substr(start, pick);
    }
};


