// https://leetcode.com/problems/maximal-rectangle/

/**
 * 
 * 
 * Logic: Must have done the largest rectangle in histogram problem first.
 * This is a 2D version of the largest rectangle in histogram problem.
 * We can think of each row in the matrix as a histogram, where the height of each
 * bar is the number of consecutive '1's in that column up to that row.
 * We can then use the largest rectangle in histogram algorithm to find the maximum rectangle area for each
 * row, updating the histogram heights as we go.
 * 
 * The overall time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
 */
class Solution {
    public:
    
        int calculateMaxRectangle(int leftInd, int rightInd, int height) {
            return height * (rightInd - leftInd - 1);
        }
    
        int maxRectangleAreaHistogram(vector<int>& histo) {
            int result=0;
            stack<int> prevSmallest;
    
            for(int i=0;i<histo.size();i++) {
                while(!prevSmallest.empty() && histo[prevSmallest.top()]>=histo[i]) {
                    int topInd = prevSmallest.top();
                    prevSmallest.pop();
                    int previousInd = prevSmallest.empty() ? -1 : prevSmallest.top();
                    result = max(result, calculateMaxRectangle(previousInd, i, histo[topInd]));
                }
                prevSmallest.push(i);
            }
            while(!prevSmallest.empty()) {
                int topInd = prevSmallest.top();
                prevSmallest.pop();
                int previousInd = prevSmallest.empty() ? -1 : prevSmallest.top();
                result = max(result, calculateMaxRectangle(previousInd, histo.size(), histo[topInd]));
            }
            return result;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            int maxRectangleSeen=0;
            vector<int> histo(matrix[0].size(), 0);
    
            for(int i=0;i<matrix.size();i++) {
                for(int j=0;j<matrix[i].size();j++) {
                    if(matrix[i][j]=='1') {
                        histo[j]++;
                    } else {
                        histo[j]=0;
                    }
                }
                maxRectangleSeen = max(maxRectangleSeen, maxRectangleAreaHistogram(histo));
            }
            return maxRectangleSeen;
        }
    };