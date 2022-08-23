// https://leetcode.com/problems/spiral-matrix/

/**
 * LOGIC: Applied basic recursion
 * 
 */ 
class Solution {
public:
    
    bool right(vector<vector<int>>& matrix, int &ind, int &jnd, vector<int>& res) {
        if(ind<0 || jnd<0 || ind>=matrix.size() || jnd>=matrix[ind].size()) return false;
        if(matrix[ind][jnd]==INT_MAX) return false;
        int j = jnd;
        for(;j<matrix[ind].size();j++) {
            if(matrix[ind][j]==INT_MAX) break;
            res.push_back(matrix[ind][j]);
            matrix[ind][j]=INT_MAX;
        }
        jnd = j-1;
        ind++;
        return true;
    }
    
    bool bottom(vector<vector<int>>& matrix, int &ind, int &jnd, vector<int>& res) {
        if(ind<0 || jnd<0 || ind>=matrix.size() || jnd>=matrix[ind].size()) return false;
        if(matrix[ind][jnd]==INT_MAX) return false;
        int i = ind;
        for(;i<matrix.size();i++) {
            if(matrix[i][jnd]==INT_MAX) break;
            res.push_back(matrix[i][jnd]);
            matrix[i][jnd]=INT_MAX;
        }
        jnd--;
        ind = i-1;
        return true;
        
    }
    
    bool left(vector<vector<int>>& matrix, int &ind, int &jnd, vector<int>& res) {
        if(ind<0 || jnd<0 || ind>=matrix.size() || jnd>=matrix[ind].size()) return false;
        if(matrix[ind][jnd]==INT_MAX) return false;
        int j = jnd;
        for(;j>=0;j--) {
            if(matrix[ind][j]==INT_MAX) break;
            res.push_back(matrix[ind][j]);
            matrix[ind][j]=INT_MAX;
        }
        jnd = j+1;
        ind--;
        return true;  
    }
    
    bool up(vector<vector<int>>& matrix, int &ind, int &jnd, vector<int>& res) {
        if(ind<0 || jnd<0 || ind>=matrix.size() || jnd>=matrix[ind].size()) return false;
        if(matrix[ind][jnd]==INT_MAX) return false;
        int i = ind;
        for(;i>=0;i--) {
            if(matrix[i][jnd]==INT_MAX) break;
            res.push_back(matrix[i][jnd]);
            matrix[i][jnd]=INT_MAX;
        }
        jnd++;
        ind = i+1;
        return true;
    }
    
    void helper(vector<vector<int>>& matrix, int &ind, int &jnd, vector<int>& res) {
        while(matrix[ind][jnd]!=INT_MAX) {
            right(matrix, ind, jnd, res);
            bottom(matrix, ind, jnd, res);
            left(matrix, ind, jnd, res);
            up(matrix, ind, jnd, res);
            if(ind<0 || jnd<0 || ind>=matrix.size() || jnd>=matrix[ind].size()) return;
        }
        return;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int a = 0, b=0;
        helper(matrix, a, b, res);
        return res;
    }
};