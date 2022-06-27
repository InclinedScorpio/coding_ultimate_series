// https://leetcode.com/problems/largest-rectangle-in-histogram/

/**
 * 
 * LOGIC: Think of naieve solution initially
 * - At each bar we can check till left and right till where we can extend the territory of the height of current bar
 * - To check that, at each bar we need to move left and right and see the range
 * - Which will  be O(N^2)
 * 
 * - We are literally checking the " NEXT SMALLEST " at each bar!
 * - We have already done "NEXT GREATEST" question before and next smallest can be done similar using a stack
 * - Now use 2 arrays and for one check next smallest from going from left to right (tells which is smaller in the left)
 * - And go from right to left as well which tells which one is next smaller in right
 * 
 * - Now just iterate and do maths to check till where the territory can be extended, calculate the area and return the maximum area 
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size());
        stack<int> st;
        
        for(int i=0;i<heights.size();i++) {
            if(st.empty()) {
                left[i] = 0; 
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if(st.empty()) {
                left[i] = 0;
            } else {
                left[i] = st.top()+1;
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        vector<int> right(heights.size());
        
        for(int i=heights.size()-1;i>=0;i--) {
            if(st.empty()) {
                right[i] = heights.size()-1;
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if(st.empty()) {
                right[i] = heights.size()-1;
            } else {
                right[i] = st.top()-1;
            }
            st.push(i);
        }
        
        int largestRectangle=INT_MIN;
        for(int i=0;i<heights.size();i++) {
            int area = ((right[i] - left[i] + 1) * heights[i]);
            if(area>largestRectangle) largestRectangle = area;
        }
        return largestRectangle;
    }
};