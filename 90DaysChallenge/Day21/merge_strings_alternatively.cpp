// https://leetcode.com/problems/merge-strings-alternately/description

/**
 * Problem requires understanding of pointer
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int str1=0, str2=0;
        string str = "";
        while(str1<word1.length() && str2<word2.length()) {
            str = str + word1[str1];
            str = str + word2[str2];
            str1++;str2++;
        }
        while(str1 < word1.length()) {
            str+=word1[str1++];
        }
        while(str2 < word2.length()) {
            str+=word2[str2++];
        }
        return str;
        
    }
};