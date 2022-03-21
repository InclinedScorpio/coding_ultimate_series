// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/**
 * LOGIC: Think backtracking...
 * - Why? We can break problem in small parts
 * - Let's take 2, 3 are (abc, def)
 * - Now, if we get "d", "e", "f" - we can attach items from '2'-abc to get required ans
 * - How?
 * - Let's say somehow you got "d","e","f"
 * - Now it's '2' remaining...
 * - a * ["d", "e", "f"], b * ["d", "e", "f"], c * ["d", "e", "f"]
 * - ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"];- answer!
 * 
 * - How we did it?
 * - We thought of keeping 2 and solving 3 and then merging 2 with result
 * - So if we have 2,3,4, We can keep 2 and solve for 3,4
 * - Now again keep 3 and solve for 4...
 * - Once 4 is solved, merge 3 to 4 (like how we did 2, 3 above)
 * - Once solved return and now merged 2 with (result of 3 & 4)
 * 
 * - NOTE: For last iteration (base case) we are returning ""
 * - Why? because in logic we are appending the returned data to previous one
 * - If you don't return "" you will else have to use (if, else)- but that's not clever
 * 
 */ 
class Solution {
public:
    map<char, string> store = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    vector<string> getKPC(string str) {
        if(str.length()==0) return {""};   //  base case- imp to understand

        char currChar = str[0]; // keeping first char and sending rest to next step
        string leftOver = str.substr(1, str.length()-1);
        vector<string> kpc = getKPC(leftOver); // will return result from leftOver string

        // operation
        vector<string> result;
        string curr = this->store[currChar];
        for(int i=0;i<curr.length();i++) {
            for(string c: kpc) {
                result.push_back(curr[i]+c);
            }
        }
        return result;
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        return getKPC(digits);
    }
}
