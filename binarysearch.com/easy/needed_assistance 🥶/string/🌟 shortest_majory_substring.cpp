// https://binarysearch.com/problems/Shortest-Majority-Substring

/**
 * LOGIC: The logic was basic, but to understand, we need to take some examples
 * - abccde - Answer is 2, what else can be the answer?
 * - abcdce - Answer 3
 * - abcdkce - Can't be the answer as c _  _ c is 4 character with 2 repeating!
 * - abcdeckkc - Still -1
 * - abcdcdcdc - 2! because smallest required
 * 
 * - So, we see answer would be only 2, 3, or -1 (as smallest one is required)
 * - Now to find if answer is 2 or 3 is easy!
 * 
 * COMPLEXITY: O(N)
 */ 
int solve(string s) {
    for(int i=1;i<s.length();i++) {
        if(s[i]==s[i-1]) return 2;
    }
    for(int i=2;i<s.length();i++) {
        if(s[i]==s[i-2]) return 3;
    }
    return -1;
}