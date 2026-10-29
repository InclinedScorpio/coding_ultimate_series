// https://leetcode.com/problems/word-search/description/?utm_source=chatgpt.com

class Solution {
public:
    bool exists(vector<vector<char>>& board, string& word, pair<int, int> ptr, int ind,
    vector<vector<int>>& trackGrid) {
        if(ind==word.size()) return true;
        int i=ptr.first, j=ptr.second;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) {
            return false;
        }
        if(board[i][j]!=word[ind]) {
            trackGrid[i][j] = 0;
            return false;
        }
        if(trackGrid[i][j]==1) {
            return false;
        }

        trackGrid[i][j] = 1;
        bool tracker=false;
        bool result= (
        this->exists(board, word, {i-1, j}, ind+1, trackGrid) ||
        this->exists(board, word, {i, j-1}, ind+1, trackGrid) ||
        this->exists(board, word, {i+1, j}, ind+1, trackGrid) ||
        this->exists(board, word, {i, j+1}, ind+1, trackGrid)
        );
        trackGrid[i][j] = 0;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> gridTracker(board.size(), vector<int>(board[0].size(), 0));

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]==word[0]) {
                    if(exists(board, word, make_pair(i, j), 0, gridTracker)) return true;
                }
            }
        }
        return false;
    }
};