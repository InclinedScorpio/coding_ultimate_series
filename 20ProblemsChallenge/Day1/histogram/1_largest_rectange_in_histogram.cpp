// https://leetcode.com/problems/largest-rectangle-in-histogram/


/**
 * Logic:
 * This is optimised stack solution.
 * Why? Because earlier I kept both left and right indices in the stack.
 * But now I am only keeping the right index in the stack.
 * The left index is calculated when we pop the top element from the stack.
 * This way we can calculate the height of the rectangle in O(1) time.
 * The overall time complexity is O(n) because we are iterating through the heights array once
 * 
 */
class Solution {
    public:
    
        int calculateHeight(int rightInd, int leftInd, int height) {
            return height * (rightInd-leftInd -1);
        }
    
        int largestRectangleArea(vector<int>& heights) {
            int result=0;
            stack<int> myStack;
    
            for(int i=0;i<heights.size();i++) {
                while(!myStack.empty() && heights[myStack.top()]>=heights[i]) {
                    int topRemoveInd = myStack.top();
                    myStack.pop();
                    // cal for topRemoveInd
                    int leftInd = myStack.empty() ? -1 : myStack.top();
                    result = max(result, calculateHeight(i,leftInd, heights[topRemoveInd]));
                }
                myStack.push(i);
            }
    
            // take care for rest of them
            while(!myStack.empty()) {
                int topRemoveInd = myStack.top();
                myStack.pop();
                // cal for topRemoveInd
                int leftInd = myStack.empty() ? -1 : myStack.top();
                result = max(result, calculateHeight(heights.size(),leftInd, heights[topRemoveInd]));
            }
    
            return result;
        }
    };