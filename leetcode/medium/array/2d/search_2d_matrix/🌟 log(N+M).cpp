// https://leetcode.com/problems/search-a-2d-matrix/

/**
 * LOGIC: See closely, it's given first row first is > prev row last
 * - That means if we flatten it up, we will get a whole sequence of number from 0,0 to last,last
 * - Hence a single logN can work here
 * 
 * - Only thing to note here is that rather than index, we will take our indices as usual
 * - And to check value we can make use of /COL & %COL accordingly!
 * 
 * COMPLEXITY: O(log (M+N))
 * 
 */ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first=0, last=(matrix.size()*matrix[0].size()) - 1;
        
        int col = matrix[0].size();
        while(first<=last) {
            int mid = first + (last - first)/2;
            if(matrix[mid/col][mid%col]==target) return true;
            else if(matrix[mid/col][mid%col]>target) last = mid - 1;
            else first = mid + 1;
        }
        return false;
    }
};