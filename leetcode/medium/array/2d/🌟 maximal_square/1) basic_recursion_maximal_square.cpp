// https://leetcode.com/problems/maximal-square/

/**
 * LOGIC: Intuition behind this problem is little tedious, yet simple
 * - consider a index in 2d array and top-left diagonal index
 * - Let's say top-left diagonal index is 1 (square of size 1x1) so for current index to make it 2x2 -> we must have atleast 1 ->'1' above and 1->'1' on left
 * - ... then only the current index can help the top-left get into 2x2
 * 
 * - What if top-left is 2 (2x2 formed?) -> means from current index, now we need to check if we have 2 '1' above and 2 '1' on left
 * - If yes, then current index can help form the top-left 2 into 3
 * 
 * - The approach is time consuming as each time we are checking how many 1 are on top so we can also make use of cache to check how many are above
 * - This will save the 'checkTop' and 'checkLeft' from iterating and we can simply check top and left from cache! (will be done separately)
 * 
 */ 
class Solution {
public:
    
    int  checkTop(vector<vector<char>>& matrix, int ind, int jnd, int reducer) {
        if(reducer==0) return 0;
        if(matrix[ind][jnd]=='1') {
            return checkTop(matrix, ind-1, jnd, reducer-1) + 1;
        }
        return 0;
    }
    
    int  checkLeft(vector<vector<char>>& matrix, int ind, int jnd, int reducer) {
        if(reducer==0) return true;
        if(jnd<0) return false;
        if(matrix[ind][jnd]=='1') {
            return checkLeft(matrix, ind, jnd-1, reducer-1)+1;
        }
        return false;
    }
    
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
        
        int topHasEqOnes = checkTop(matrix, ind-1, jnd, existingSquare);
        int leftHasEqOnes = checkLeft(matrix, ind, jnd-1, existingSquare);
                
        cache[ind][jnd] = min(topHasEqOnes, min(leftHasEqOnes, existingSquare)) + 1;
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