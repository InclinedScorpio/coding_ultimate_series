// https://leetcode.com/problems/search-a-2d-matrix/

/**
 * LOGIC: The way 2D matrix is sorted clearly asks you to implement Binary Search two times
 * - One from top to bottom to see in which interval value will lie
 * - And the other to search no. in the row
 * 
 * COMPLEXITY: O(logM + logN)
 * 
 */ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0, bottom=matrix.size()-1;
        while(top<=bottom) {
            int mid = (top+bottom)/2;
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]>target) {
                bottom = mid-1;
            } else {
                top=mid+1;
            }
        }
        if(bottom<0) bottom=0;
        
        int left=0, right=matrix[bottom].size()-1;
        while(left<=right) {
            int mid = (left+right)/2;
            if(matrix[bottom][mid]==target) return true;
            if(matrix[bottom][mid]>target) {
                right = mid-1;
            } else {
                left=mid+1;
            }
        }
        return false;
    }
};