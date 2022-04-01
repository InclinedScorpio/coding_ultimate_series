// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/**
 * LOGIC: Basic DP Problem
 * - Try in scratch, figure out different cases 
 * - Dp flow will be from left to right
 * 
 * ALTERNATIVE: Use Sliding Window Approach! @see unique_string problem
 * 
 * COMPLEXITY: O(N) 
 * 
 */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        
        vector<int> store(s.length(), 0);
        map<char, int> lastInd;
        store[0]=1; // first element will obviously be length 1 substring
        lastInd[s[0]]=0; // store first element in map
    
        for(int i=1;i<s.length();i++) {
            if(lastInd.find(s[i])==lastInd.end()) { // if doesn't exists- means existing length + 1 is answer for sure
                lastInd[s[i]]=i;
                store[i]=store[i-1]+1;
            } else { // in map exists hence- 2 conditions are possible
                int indexDiff = i-lastInd[s[i]];
                lastInd[s[i]]=i;
                if(indexDiff>store[i-1]) { // if repeatable character diff is > previous count then means current can be + 1
                    store[i]=store[i-1]+1;
                }else { // else we need to have index diff (Try this in Scratch to understand)
                    store[i]=indexDiff;
                }
            }
        }
        return *max_element(store.begin(), store.end());
    }
};