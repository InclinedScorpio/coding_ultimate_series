
/**
 * Given a string, find the smallest window (substring) which contains all distinct characters of the given input string.
 * 
 * Sample Inputs:
 * aabcbcdbcaaad
 * aaaa
 * 
 * Sample Outputs:
 * dbca
 * a
 * 
 * Explanation : The smallest window is "dbca" as it contains all the distinct letters from input string. 
 * ...Similarly for the second case the answer should be 'a'.
 * 
 * 
 */

/**
 * LOGIC:
 * We need to implement sliding window here
 * 1. Keep increasing window to right till all items are covered
 * 2. Once covered, start decreasing items from left...
 * 3. This will help in finding the smallest/minimum windowORsubstring
 * 4. As soon as items are again missing, stop decreasing window from right
 * 5. Now again start expanding from right...
 * 6. Save the smallest one while doing this
 * 
 * NOTE: Similar to @see minimum window substring problem
 * 
 * CATEGORY: HARD 
 */ 
#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string str){
    set<char> store;
    for(char toStore: str) store.insert(toStore);
    int uniqueLen = store.size();
    
    map<char, int> current;
    
    int i=0, j=0;
    int allIncluded = false;
    int resultI=0, resultJ=0;
    bool isResultStored=false;
    
    while(allIncluded || j<str.length()) {
        if(allIncluded) {// increment i (window decreasing)
            if(current.find(str[i])!=current.end()) {
                if(current[str[i]]>1) {
                    current[str[i]]--;
                } else {
                    current[str[i]]--;
                    allIncluded = false;
                    uniqueLen++;
                }
            }
            i++;
            if(uniqueLen==0) {
                allIncluded = true;
                if(j-i < resultJ-resultI || !isResultStored) {
                    isResultStored = true;
                    resultI = i;
                    resultJ = j;
                }
            }
        } else {// increment j (window increasing)
            if(current.find(str[j])==current.end()) {
                uniqueLen--;
                current[str[j]]++;
            } else {
                current[str[j]]++;
            }
            j++; // do it before if below as (0, 2) means take 2 item from 0 whereas we want 3(0-2) so take j one more that's why incrementing first
            if(uniqueLen==0) {
                allIncluded = true;
                if(j-i < resultJ-resultI || !isResultStored) {
                    resultI = i;
                    resultJ = j;
                }                
            }
        }
    }
    
    return str.substr(resultI, (resultJ-resultI));
}