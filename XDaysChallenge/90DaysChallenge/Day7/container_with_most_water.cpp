// https://leetcode.com/problems/container-with-most-water/description/

/**
 * Problem requires understanding of two pointer approach
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int currMax=0;
        for(int i=0, j=height.size()-1;i<j;) {
            currMax = max(currMax, min(height[i], height[j])*(j-i));
            if(height[i]>height[j]) --j;
            else ++i;
        }
        return currMax;
    }
};