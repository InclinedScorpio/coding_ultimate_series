// https://leetcode.com/problems/container-with-most-water/

/**
 * LOGIC: Don't confuse this with Trap Water problem
 * - Here requirement is to find biggest container which can be formed using the bars and X axis
 * 
 * So main logic is
 * O(N^2)- Either take 2-2 pairs and find the max
 * 
 * O(N)- Think about the 2 pointer approach
 * - Keep 2 ptr at extreme ends
 * - Now the smaller height bar would have got the best area it could generate
 * - Why? because even a bigger, smaller, same bar in btw couldn't do any better
 * - Hence move the ptr which represents the smaller height
 * - Keep moving till both ptr are '=='
 * - By doing this, we are calculating best area which can be represented by each bar
 * 
 * COMPLEXITY:O(N)
 * 
 */ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxWater=INT_MIN;
        while(left<right) {
            int minHeight = min(height[left], height[right]);
            int currArea = (right-left) * minHeight;
            maxWater = max(maxWater, currArea);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return maxWater;
    }
};