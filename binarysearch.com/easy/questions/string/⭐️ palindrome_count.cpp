// https://binarysearch.com/problems/Palindrome-Count

/**
 * LOGIC: In palindrome we care about first half
 * - So let's say we have 'ab' and 4  length palindrome needs to be created
 * - Note: Char can repeat
 * So now we have total _ _, _ _ 4 different places to create palindrome
 * - But we are concerned with intial 2 - _ _
 * Q) How many ways can you insert 'ab' inside these 2 blank?
 * A) 2 * 2 times
 * Q) What if it were 5 blanks _ _ _ _ _
 * A) Now 2 * 2 * 2
 * 
 * Means, string_size ^ no_of_blanks (LOGIC !!)
 * 
 */
int solve(string s, int k) {
    set<char> store;
    for(int i=0;i<s.length();i++) store.insert(s[i]);
    int fillTill=(k/2);
    if(k%2!=0) {
        fillTill = (k)/2;
        fillTill++;
    }
    return pow(store.size(), fillTill);
}