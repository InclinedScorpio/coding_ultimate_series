// https://leetcode.com/problems/word-search/description/

class Solution {
    public:
        bool helper(vector<vector<char>>& board, int i, int j, 
        vector<vector<bool>>& isVisited, string& word, int covered) {
            if(covered==word.size()) return true;
            if(
                i>=board.size() 
                || i<0 
                || j>=board[i].size() 
                || j<0 
                || isVisited[i][j]
                || board[i][j]!=word[covered]
            ) return false;
    
            isVisited[i][j] = true;
    
            if(board[i][j]==word[covered]) {
                // trying going everywhere
                for(int iter=-1;iter<=1;iter++) {
                    for(int jter=-1;jter<=1;jter++) {
                        if((iter==0 && jter==0) || (iter==-1 && jter==-1) || (iter==1 && jter==1) || (iter==-1 && jter==1) || (iter==1 && jter==-1)) continue;
                        if(this->helper(board, i+iter, j+jter, isVisited, word, covered+1)) return true;
                    }
                }
            }
            isVisited[i][j] = false;
            return false;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            for(int i=0;i<board.size();i++) {
                vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
                for(int j=0;j<board[i].size();j++) {
                    if(this->helper(board, i, j, isVisited, word, 0)) return true;
                }
            }
            return false;
        }
    };