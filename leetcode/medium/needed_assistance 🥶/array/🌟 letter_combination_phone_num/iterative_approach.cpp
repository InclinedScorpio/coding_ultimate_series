// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/**
 * LOGIC: Check Recursive first, it will easier then :)
 * - Use "" initially - the point to note
 * - After that we keep picking last char and appending it
 * - Basic logic
 * 
 * NOTE: Observation was iterative was Faster than Recursive 
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

    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        
        vector<string> result = {""}; // base Case in recursive :)
        vector<string> res;

        for(int i=digits.size()-1;i>=0;i--) {
            for(int j=0;j<result.size();j++) {
                string currStr = this->store[digits[i]];
                for(char c: currStr) {
                    res.push_back(c + result[j]);
                }
            }
            result = res;
            res = {};
        }
        return result;
    }
};
