// https://practice.geeksforgeeks.org/problems/power-set4302/1#

/**
 * 
 * LOGIC: We already know the recusive way of doing this
 * 
 * - Here we need find subsequence using the bits method
 * - Normally if we see the bits 
 * a b c
 * -----
 * 0 0 0
 * 0 0 1
 * 0 1 0
 * 0 1 1
 * 1 0 0
 * 1 0 1
 * 1 1 1
 * Are nothing but subsequence, so we can make use of them
 * We can take each of them and see which among abc we need to pick them
 * 0 0 0 -> a b c -> "" (Pick nothing)
 * 0 0 1 -> a b c -> "a"
 * 0 1 1 -> a b c -> "ab"
 * 
 * Considering 0 1 1 -> "ab" (how we found it?)
 * for 'a' we can do 2^0 = 1 ( 0 0 1 ) & (0 1 1) -> pick 'a' (getting 1)
 * for 'b' we can do 2^1 = 2 ( 0 1 0 ) & (0 1 1) -> pick 'b' (getting 1)
 * for 'c' we can do 2^2 = 4 ( 1 0 0 ) & (0 1 1) -> don't pick (as we are getting 0)
 * 
 * COMPLEXITY: O(2^(len_of_str))
 * 
 */
class Solution {
	public:
		vector<string> AllPossibleStrings(string s){
		    int total = 1<<s.length();
		    vector<string> result;
		    for(int i=0;i<total;i++) {
		        string str="";
		        for(int j=0;j<s.length();j++) {
		            if((1<<j) & i) {
		                str+=s[j];
		            }
		        }
		        if(str.length())
		        result.push_back(str);
		    }
		    sort(result.begin(), result.end());
		    return result;
		}
};