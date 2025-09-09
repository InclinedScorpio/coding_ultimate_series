// https://leetcode.com/problems/edit-distance/?envType=problem-list-v2&envId=plakya4j


/**
 * 
 * Start thinking of all the possibilities as we can't think of any direct solution
 * Think of i and j starting from 0 and going through all possibilities (3 here)
 * 
 * Important to note is we don't need to change the strings, hypothetically we can think and proceed
 * as end of the day we just need the count of operations (not the actual changes in string)
 * 
 * ABCD
 * BC
 * so, if you are at (0, 0) then you can add B in first string, and move to A(0) and C(1) - A stays at 0 as we added B before it(hypothetically)
 * Memoization time complexity O(m*n)
 * 
 */
class Solution {
    private:
        string str1, str2;
    
    public:
    
        // trying to make 1 same as 2
        int helper(int i, int j, vector<vector<int>>& dp) {
            if(i==str1.length()) return str2.length() - j;
            if(j==str2.length()) return str1.length() - i;
            if(dp[i][j]!=-1) return dp[i][j];
    
            // are same?
            if(str1[i] == str2[j]) return this->helper(i+1, j+1, dp);
    
            // not same - do something
            //1) insert the character in 1
            int res = 1 + helper(i, j+1, dp); // i will remain same (we inserted the character before it - hypothetic - no need to update string)
    
            //2) delete the character and move ahead
            res = min(res, 1 + helper(i+1, j, dp)); // because character is deleted so move i ahead
    
            //3) replace the character and move
            res = min(res, 1 + helper(i+1, j+1, dp)); // because replaced so now both matched, both move
    
            return dp[i][j]=res;
        }
    
        int minDistance(string word1, string word2) {
            this->str1 = word1;
            this->str2 = word2;
    
            vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
            return this->helper(0, 0, dp);
            
        }
    };