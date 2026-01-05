// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description

class Solution {
public:
    void helper(vector<string>& phone, string& digits, int ind, int interInd, string currString, vector<string>& res) {
        if(digits.size()==ind) {
            if(currString!="") res.push_back(currString);
            return;
        }
        if(phone[digits[ind] - '0'].length()==interInd) return;
        
        // pick from interInd && increase ind - picked
        this->helper(phone, digits, ind+1, 0, currString + phone[digits[ind] - '0'][interInd], res);

        // increaseinterind increase and don't increase ind
        this->helper(phone, digits, ind, interInd+1, currString, res);
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string emptyString="";
        this->helper(phone, digits, 0, 0, emptyString, res);
        return res;
    }
};