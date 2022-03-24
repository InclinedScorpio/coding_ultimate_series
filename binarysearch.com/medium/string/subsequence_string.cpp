// https://binarysearch.com/problems/Subsequence-Strings

/**
 * LOGIC: Basic
 * - Keep index on s1 and keep record which ones appeared
 * - Once character appears, increment the index
 * - Once index at the last, all the characters in s1 appeared, return true
 * 
 * - It's easier than subset_string - KMP Used
 * 
 */ 
bool solve(string s1, string s2) {
    if(s1.length()==0) return true;
    int index=0;
    for(int i=0;i<s2.length();i++) {
        if(s2[i]==s1[index]) index++;
        if(index==s1.length()) return true;
    }
    return false;
}
