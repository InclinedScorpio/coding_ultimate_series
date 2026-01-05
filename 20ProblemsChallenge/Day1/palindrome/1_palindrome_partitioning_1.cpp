// https://leetcode.com/problems/palindrome-partitioning/

/**
 * Logic is first to understand this is a recursion problem.
 * Rather than thinking of returning results, think of passing & referenced one and storing final result
 * once you are able to reach the end of the string.alignas
 * 
 * 
 * Each step find the palindromes you can find and it will become part of solution and for rest of part, backtrack
 * and find the next palindrome.
 * 
 * We have memoized just the isPalindrome part here to avoid recomputing the same substring again and again.
 */
class Solution {
    public:
        bool isPalindrome(string& s, int left, int right, vector<vector<int>>& memo) {
            if(memo[left][right]!=-1) return memo[left][right];
            int leftStored=left, rightStored=right;
            while(left<=right) {
                if(s[left]!=s[right]) {
                    memo[leftStored][rightStored]=0;
                    return false;
                }
                left++;
                right--;
            }
            memo[leftStored][rightStored]=1;
            return true;
        }
    
        void helper(string& s, int ind, vector<string> path,vector<vector<string>>& result, vector<vector<int>>& memo) {
            if(ind==s.length()) {
                result.push_back(path);
                return;
            }
    
            for(int iter=ind;iter<s.length();iter++) {
                if(isPalindrome(s, ind, iter, memo)) {
                    vector<string> newPath = path;
                    newPath.push_back(s.substr(ind, iter-ind+1));
                    helper(s, iter+1, newPath, result, memo);
                }
            }
        }
        
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;
            vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
            helper(s, 0, {}, result, memo);
            return result;
        }
    };