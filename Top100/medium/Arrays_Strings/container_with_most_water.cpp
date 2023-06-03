// https://leetcode.com/problems/container-with-most-water/description/

/**
 * 
 * LOGIC: Move left when it's smaller than right
 * Move right if smaller than left
 * 
 */ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right = height.size()-1;

        int maxAreaTill=0;
        while(left<right) {
            int area = (right-left)*min(height[left], height[right]);
            if(area>maxAreaTill) maxAreaTill = area;
            if(height[left]<=height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxAreaTill;
    }
};
