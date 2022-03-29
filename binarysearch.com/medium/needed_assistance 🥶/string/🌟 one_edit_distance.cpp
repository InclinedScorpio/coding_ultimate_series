// https://binarysearch.com/problems/One-Edit-Distance

/**
 * LOGIC: Levenshtein problem basically but it will give TLE
 * - Levenshtein finds min edit distance
 * - Here one edit distance is required
 * 
 * - So, 2 strings cant be more than x-y > 1 length (otherwise > 2 edits)
 * - Main Logic: (2 ptr approach)
 * - If char are equal - increment both
 * - If char are not equal and one string is longer...
 * - delete curr character from curr string...
 * - This means now after deletion both string must be equal...
 * - Promatically we can just increment the ptr in longer string and keep checking
 * - If edits(changes) are more than 1 that means false else true
 * 
 * NOTE: Deleting character is similar to keeping ptr pointing to smaller string there only...
 * ...and incrementing the ptr of longer string, and keep on matching thereafter.
 * 
 * COMPLEXITY: O(M+N)
 * 
 * WARNING: Levenshtein using dynamic is intriguing here but as it's 1 edit then we optimized the above way
 * - Question can be done using Levenshtein as well (only issue is it will take more time)
 * 
 */ 
bool solve(string s0, string s1) {
    int s0Length = s0.length();
    int s1Length = s1.length();
    if(abs(s0Length-s1Length)>1) return false;

    int i=0, j=0, totalEdits=0;
    
    while(i<s0Length && j<s1Length) {
        if(totalEdits>1) break;
        if(s0[i]==s1[j]) {
            i++;j++;continue;
        }
        if(s0Length==s1Length) {
            i++;
            j++;
        }else {
            if(s0Length>s1Length) {
                i++;
            }else {
                j++;
            }
        }
        totalEdits++;
    }
    if(totalEdits>1) return false;
    return true;
    
}
