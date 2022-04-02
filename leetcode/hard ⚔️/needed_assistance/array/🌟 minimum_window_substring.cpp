// https://leetcode.com/problems/minimum-window-substring/

/**
 * LOGIC: is to use sliding window here.
 * - We can use 2 pointers to keep a window
 * - If all strings in t are included, start incrementing i
 * - As soon as window doesn't contain t, start incrementing j again
 * - Stop and again start incrementing i as soon as t is included in s
 * 
 * COMPLEXITY: O(N)
 *
 */ 
class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int> store;
        map<int,int> current;
        int tLen = t.length();
        
        for(int i=0;i<t.size();i++) store[t[i]]++;

        int i=0,j=0;
        bool allIncluded=false;
        int resultI=0, resultJ=0;
        bool resultStoredOnce = false;
        
        //it's possible that j exceeds length but still allIncluded is true
        // means i can increment.
        // important to note: i!=j as all won't be included in that case
        while(allIncluded || j<s.length()) {
            if(allIncluded) { // increment i
                // remove current i from current and update allIncluded
                if(store.find(s[i])!=store.end()) {
                    current[s[i]]--;
                    if(current[s[i]] < store[s[i]]) {
                        tLen++;
                        allIncluded=false;
                    }
                }
                i++;
                if(tLen==0) {
                    allIncluded = true;
                    if((j-i)<(resultJ-resultI) || !resultStoredOnce) {
                            resultStoredOnce=true;
                            resultI=i; resultJ=j;
                    }
                } 
            } else { //increment j
                if(store.find(s[j])!=store.end()) {
                    if(store[s[j]] > current[s[j]]) tLen--;
                    if(tLen==0) {
                        allIncluded = true;
                        if((j-i)<(resultJ-resultI) || !resultStoredOnce) {
                            resultStoredOnce=true;
                            resultI=i; resultJ=j+1;
                        }   
                    } 
                    current[s[j]]++;
                }
                j++;
            }
        }
        
        return s.substr(resultI, (resultJ-resultI));   
    }
};