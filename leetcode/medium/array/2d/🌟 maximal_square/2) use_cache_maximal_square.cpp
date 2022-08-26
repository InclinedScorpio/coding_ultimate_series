// https://leetcode.com/problems/maximal-square/submissions/

/**
 * LOGIC: Here we have used 1) and used cache instead of making use of 'checkTop' and 'checkLeft' method.
 * 
 */ 
class Solution {
public:
    // The below 2 methods not required as we can check it through cache itself
    
    // int  checkTop(vector<vector<char>>& matrix, int ind, int jnd, int reducer) {
    //     if(reducer==0) return 0;
    //     if(matrix[ind][jnd]=='1') {
    //         return checkTop(matrix, ind-1, jnd, reducer-1) + 1;
    //     }
    //     return 0;
    // }
    
    // int  checkLeft(vector<vector<char>>& matrix, int ind, int jnd, int reducer) {
    //     if(reducer==0) return true;
    //     if(jnd<0) return false;
    //     if(matrix[ind][jnd]=='1') {
    //         return checkLeft(matrix, ind, jnd-1, reducer-1)+1;
    //     }
    //     return false;
    // }
    
    int  helper(vector<vector<char>>& matrix, int ind, int jnd, int& maxValue, vector<vector<int>>& cache) {
        int left = ind-1;
        int top = jnd - 1;
        
        if(jnd==matrix[ind].size()) { // extreme right bottom end
            // nextLine
            if(ind==matrix.size()-1) return 0;
            return helper(matrix, ind+1, 0, maxValue, cache);
        }
        
        if(left<0 || top<0 || matrix[left][top]=='0' || matrix[ind][jnd]=='0') { // edge cases
            cache[ind][jnd] = matrix[ind][jnd]=='1' ? 1 :0;
            maxValue = max(maxValue, cache[ind][jnd]);
            return helper(matrix, ind, jnd+1, maxValue, cache);
        }
        
        int existingSquare = cache[left][top];
        
        // int topHasEqOnes = checkTop(matrix, ind-1, jnd, existingSquare);
        // int leftHasEqOnes = checkLeft(matrix, ind, jnd-1, existingSquare);
                
        cache[ind][jnd] = min(cache[ind-1][jnd], min(cache[ind][jnd-1], existingSquare)) + 1;
        maxValue = max(maxValue, cache[ind][jnd]);
        
        return helper(matrix, ind, jnd+1, maxValue, cache);
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxValue = 0;
        helper(matrix, 0, 0, maxValue, cache);
        return maxValue*maxValue;
    }
};