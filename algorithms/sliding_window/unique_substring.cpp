// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

/**
 * QUESTION: Find longest substring which doesn't have repeating character
 * LOGIC: We basically need to keep two pointer and check of in btw character so that repetition is no there
 * - As soon as it's repeated, take i forward
 * - and remove those from set as well
 * 
 */ 
int longestNonRepeatingLetter(string s) {
     if(s.length()==0) return 0;
        
        vector<int> store(s.length(), 0);
        map<char, int> lastInd;
        store[0]=1;
        lastInd[s[0]]=0;
        
        // prateekbhaiya
        // p->0, r->1, a->2, t->3, e->4
        // 1, 2, 3, 4, 5, 
    
        for(int i=1;i<s.length();i++) {
            if(lastInd.find(s[i])==lastInd.end()) {
                lastInd[s[i]]=i;
                store[i]=store[i-1]+1;
            } else {
                int indexDiff = i-lastInd[s[i]];
                lastInd[s[i]]=i;
                if(indexDiff>store[i-1]) {
                    store[i]=store[i-1]+1;
                }else {
                    store[i]=indexDiff;
                }
            }
        }
        return *max_element(store.begin(), store.end());
}

int main() {
    string str = "prateolvekbhaiya";
    cout<<longestNonRepeatingLetter(str);
}
