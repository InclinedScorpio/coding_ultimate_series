// https://leetcode.com/problems/permutation-sequence/

/**
 * LOGIC: A naieve approach is to get next_permutation k number of times
 * - But that will take a lot of time
 * 
 * BETTERLOGIC:
 * Let's say we have n=3 so string formed -> 123
 * Q 1) Now 123 will have how many different ways where first character will be different?
 * A 1)  1 {2, 3} -> 0th way (1 as first character) -> (2) 2 ways
 *     2 {1, 3} -> 1st way (2 as first character) -> (2) 2 ways
 *     3 {1, 2} -> 2nd way (3 as first character) -> (2) 2 ways
 *                                                   -----------------
 *                                                     6 ways in total
 *                                                   -----------------
 *     1 {2, 3} -> (0-1) 0-1 sequence will be when 1 will be at first
 *     2 {1, 3} -> (2-3) 2-3 sequence will be when 2 will be at first
 *     3 {1, 2} -> (4-5) 4-5 sequence will be when 3 will be at first
 * 
 * - Now let's say we are given k=3
 * - So initially change k to 0 based index so k becomes ‘2‘
 * 
 * - Now we have "123" and 2 means we will have to goto sequence (2-3) -> which means '2' will come at first character
 * Q 2) How we know it will goto second sequence mathematically? A) Simple "123" so take "23" (2!)-> 2 ==> hence n(2)/(2!) = 1 (1st index is "2") hence 2!
 * 
 * - Now left ones are "13" -> again similar to Q 1) we can have 1 {3} and 3 {1}. So we need to pick them based on remaining k 
 * - Remaining k is n=2 % (2!)2 -> hence we will get how many steps in sequence (2-3) we need to take 
 * - Here it comes out to be 0 hence pick "1"
 * - Now at last remaining is "3" hence we pick 3
 * - So result formed is "213" which is our 3rd sequence
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    string helper(string str, int n) {
        if(str.length()==1) return str;
        // find factorial
         int nums=1;
        for(int i=1;i<=str.length()-1;i++) {
            nums=nums*i;
        }
        // get the first character at that sequence
        char save = str[n/nums];
        
        // remove that character from string
        str.erase(n/nums, 1);
        return save + helper(str, n%nums);
    }
    
    string getPermutation(int n, int k) {
        //create the string from n
        string str="";
        while(n) {
            str = to_string(n) + str;
            n--;
        }
        // k-1 is required as index starts from 0
        return helper(str, k-1);
    }
};