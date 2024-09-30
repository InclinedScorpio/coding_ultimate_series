// https://leetcode.com/problems/trapping-rain-water/

/**
 * Keeping leftMax and rightMax as a preprocessing step
 * Focus on current index, and check if it can store water
 */
class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        int leftMax=0, rightMax=0;

        for(int i=0, j=height.size()-1;i<height.size();i++, j--) {
            left[i] = leftMax;
            leftMax = max(leftMax, height[i]);
            right[j] = rightMax;
            rightMax = max(rightMax, height[j]);
        }

        int waterStored=0;
        for(int i=0;i<height.size();i++) {
            int maxCurrHeight = min(left[i], right[i]);
            if(maxCurrHeight>height[i]) {
                waterStored += (maxCurrHeight - height[i]);
            }
        }
        return waterStored;
    }
};