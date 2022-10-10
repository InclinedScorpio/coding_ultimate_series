// https://leetcode.com/problems/flip-string-to-monotone-increasing/

/**
 * LOGIC: First step which should come is recursion
 * - Then DP! but how to do dp? oops!
 * - Here we can simply check the 0's and 1's and then do the operations rather than running loops
 * - Hence we will count the ones we have seen till each index and use to know how many 1's and 0s are there each side
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    int helper(string& s, int ind, int totalOnes, vector<int>& oneTillInd) {
        int flips = 0;
        flips+=oneTillInd[ind];
        flips+=(s.length()-ind-1-(totalOnes-oneTillInd[ind]));
        return flips;
    }
    
    int minFlipsMonoIncr(string s) {
        // cout<<minVal<<endl;
        int totalOnes=0;
        vector<int> oneTillInd(s.length(), 0);

        for(int i=0;i<s.length();i++) {
            if(s[i]=='1') totalOnes++;
            oneTillInd[i]=totalOnes;
        }
        
        // edge case - if all once
        int minVal = (s.length()-totalOnes);
        
        for(int i=0;i<s.length();i++) {
            minVal = min(minVal, helper(s, i, totalOnes, oneTillInd));
        }
        return minVal;//11011
    }
};