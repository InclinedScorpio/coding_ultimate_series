// https://leetcode.com/problems/longest-common-subsequence/

/**
 * LOGIC: Just a 2d array game
 * - check if current char match, increment it then
 * - if it doesn't match, see what's the max - ongoing (left) or till previous one (up)
 *
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length() < text2.length()) return longestCommonSubsequence(text2, text1);
        vector<vector<int>> store(text1.length()+1, vector<int>(text2.length()+1, 0));
        int longest=0;
        for(int ind=1;ind<store.size();ind++) {
            bool isChoosen = false;
            for(int jnd=1;jnd<store[ind].size();jnd++) {
                int i=ind-1,j=jnd-1;
               if(text1[i]==text2[j]) {
                    isChoosen=true;
                    store[ind][jnd] = max(store[ind-1][jnd-1]+1, store[ind-1][jnd]);
               } else {
                    store[ind][jnd] = max(store[ind][jnd-1], store[ind-1][jnd]);
               }
               longest = max(longest, store[ind][jnd]);
            }
        }
        return longest;
    }
};
