// https://leetcode.com/problems/different-ways-to-add-parentheses/

/**
 * MUST DO !!
 * 
 * - Couldn't figure out the way to send indices recursively and find the num among operators
 * - Turns out question is much easier than it looks
 * - You just have to care about the operators and solve left and right side of it recursively
 * - Run a loop and do this for each operator you see
 * - Once you get left and right result, just do n^2 opertions to get all possible results
 * 
 * - How to figure out the numbers among the operators? - this is important - we can simply check if no result found that means...
 * - There were no operators and hence it's all numbers in the given expression, hence turn that expression to number and return back
 * 
 */ 
class Solution {
public:
    
    vector<int> helper(string expression, unordered_map<string, vector<int>>& dp) {
        vector<int> result;
        
        if(dp.find(expression)!=dp.end()) {
            return dp[expression];
        }
        for(int i=0;i<expression.size();i++) {
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*') {
                // left and right are my subproblems
                
                vector<int> left = helper(expression.substr(0, i), dp);
                vector<int> right = helper(expression.substr(i+1), dp);
                
                for(int l: left) {
                    for(int r: right) {
                        if(expression[i]=='-') {
                            result.push_back(l - r);
                        } else if(expression[i]=='+') {
                            result.push_back(l + r);
                        } else {
                            result.push_back(l * r);
                        }
                    }
                } 
            }    
        }
        
        if(result.size()==0) { // means no operator present
            result.push_back(stoi(expression));
        }
        
        return dp[expression] = result;
    }
    
    
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> dp;
        return helper(expression, dp);
    }
};