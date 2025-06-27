
/**
 * 
 * Top-Down Approach, recusion + memoization - DP
 * Logic is to understand this is a recursion problem.
 * And once you reach the end of string, you have a valid partition.
 * 
 * As it's repeating subproblem, we can memoize the result
 */
class Solution {
    public:
        bool isPalindrome(string&s, int left, int right) {
            while(left<=right) {
                if(s[left]!=s[right]) return false;
                left++;
                right--;
            }
            return true;
        }
    
        int helper(string& s, int ind, vector<int>& dp) {
            int counter=INT_MAX;
            if(ind>=s.length()) return -1;
            if(dp[ind]!=-1) return dp[ind];
    
            for(int i=ind;i<s.length();i++) {
                bool isPalindrome = this->isPalindrome(s, ind, i);
                if(isPalindrome) {
                    int nextPalindromeCounter = this->helper(s, i+1, dp);
                    if(nextPalindromeCounter!=INT_MAX) {
                        counter = min(counter, nextPalindromeCounter);
                    }
                }
            }
            return dp[ind] = counter+1;
        }
        
        int minCut(string s) {
            vector<int> dp(s.length()+1, -1);
            return helper(s, 0, dp);
        }
    };