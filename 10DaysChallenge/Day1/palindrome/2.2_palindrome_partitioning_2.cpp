// https://leetcode.com/problems/palindrome-partitioning-ii/

/**
 * 
 * 
 * Logic is first to understand this is a recursion problem.
 * Then do the bottom up approach - tabulation (DP)
 * 
 * 1) In recursion we were going ind from 0 to n-1, here we will go from n-1 to 0
 * 2) Inside for loop, everything remains same, just instead of calling recursion, we will use dp array to get the result.
 * 3) We will initialize dp[n] = 0 and dp[n-1]
 * 4) Finally return dp[0]-1 as we are counting partitions, but we need cuts.
 * 
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
            vector<int> dp(s.length()+1, INT_MAX);
            dp[s.length()]=0;
            dp[s.length()-1]=0;
    
            for(int ind=s.length()-1;ind>=0;ind--) {
                int counter=INT_MAX;
                for(int i=ind;i<s.length();i++) {
                    bool isPalindrome = this->isPalindrome(s, ind, i);
                    if(isPalindrome) {
                        int nextPalindromeCounter = dp[i+1];
                        if(nextPalindromeCounter!=INT_MAX) {
                            counter = min(counter, nextPalindromeCounter);
                        }
                    }
                }
                if(counter==INT_MAX) dp[ind] = INT_MAX;
                else dp[ind] = counter+1;
            }
            return dp[0] - 1;
        }
    };