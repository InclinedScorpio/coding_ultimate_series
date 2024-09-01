// https://leetcode.com/problems/word-search/description/

/**
 * Problem requires understanding of backtracking and how to use it to solve the problem
 * Don't get intimidated by time complexity! Keep doing until asked
*/
class Solution {
public:
    bool checker(vector<vector<char>>& board, int i, int j, string& word, int indWord, vector<vector<int>>& dp) {
        if(indWord==word.length()) return true;
        if(i==board.size() || i<0 || j<0 || j==board[0].size()) return false;
        if(dp[i][j]) return false;
        dp[i][j] = 1;

        if(board[i][j]==word[indWord]) indWord++;
        else {
            dp[i][j]=0;
            return false;
        }

        // go right
        bool res = checker(board, i, j+1, word, indWord, dp);
        if(res) return true;

        // go bottom
        res = checker(board, i+1, j, word, indWord, dp);
        if(res) return true;

        // go left
        res = checker(board, i, j-1, word, indWord, dp);
        if(res) return true;

        // go top
        res = checker(board, i-1, j, word, indWord, dp);
        if(res) return true;

        dp[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                vector<vector<int>> dp(board.size()+1, vector<int>(board[0].size()+1, 0));
                if(checker(board, i, j, word, 0, dp)) return true;
            }
        }
        return false;
    }
};