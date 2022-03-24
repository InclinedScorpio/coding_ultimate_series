// https://leetcode.com/problems/generate-parentheses/

/**
 * LOGIC: It's basic backtracking but hard to understand that it is
 * - How to know it's backtracking?
 * - At each poin we have 2 choices - '(' or ')'
 * - Also we need to find each possible way
 * - Hence it's a hint that recursion must be used and it's backtracking
 * - Obviously base case and operation needs to be implemented.
 * 
 * COMPLEXITY: O(2^N)
 */ 
class Solution {
public:
    
    vector<string> helper(string curr, int left, int right) {
        /*
        Scratch work
        1. (  - left: 2 | right: 3
        2. (( - left: 1 | right: 3
        3. ((( - left:0 | right: 3
        4. (((( - left:-1 | right: 3
        5. ((() - left:0 | right: 2
        6. ((()) - left: 0 | right: 1
        7. ((())) - left: 0 | right: 0
        */
        if(right<left || left==-1) return {};
        if(left==0 && right==0) return { curr };
        
        vector<string> res1 = this->helper(curr + '(', left-1, right);
        vector<string> res2 = this->helper(curr + ')', left, right-1);
        vector<string> res;
        for(string str: res1) res.push_back(str);
        for(string str: res2) res.push_back(str);
        
        return res;
    }
    
    vector<string> generateParenthesis(int n) {
        string str = "(";
        int left = n - 1;
        int right = n;
        return this->helper(str, left, right);
    }
};