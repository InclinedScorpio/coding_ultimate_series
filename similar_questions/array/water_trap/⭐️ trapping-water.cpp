// https://leetcode.com/problems/trapping-rain-water/

/**
 * LOGIC: 
 * - Max water accumulated at given index will be MIN of left height, right height...
 * - Why? It's basic logic that left max and right max - whatever would be minimum, will define the max water that can accumulate at that index
 * - BUT! we need to '-' the height of building at that index too! so...
 * - Algo becomes min(leftMax, rightMax) '-' currHeight
 * 
 * 
 * - finding leftMax and rightMax is easy by O(N) both so O(2N)
 * - Now for each index we just need to see what's the min left or right boundary
 * - and '-' the height of the current building 
 * 
 * COMPLEXITY: O(3N)
 * 
 */ 
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMaxArr;
        vector<int> rightMaxArr;
        
        int leftMax = height[0];
        int rightMax = height[height.size()-1];
        
        // preparing the left Maximum and right Maximum at each index
        int reverseInd=height.size()-1; 
        for(int i=0;i<height.size();i++, reverseInd--) {
            if(height[i]>leftMax) {
                leftMax  = height[i];
                leftMaxArr.push_back(leftMax);
            } else {
              leftMaxArr.push_back(leftMax);  
            }    
            
            if(height[reverseInd]>rightMax) {
                rightMax = height[reverseInd];
                rightMaxArr.push_back(rightMax);
            }else {
                rightMaxArr.push_back(rightMax);
            }
        }

        reverse(rightMaxArr.begin(), rightMaxArr.end()); // reverse the rightMax array as it's calculated from last
        
        // left, right max array are ready! Now just run our basic algo!
        int sum=0;
        for(int i=0;i<height.size();i++) {
            int minHeight = min(leftMaxArr[i], rightMaxArr[i]);
            int minHeightSubCurrHeight = minHeight - height[i];
            if(minHeightSubCurrHeight>0) {
                sum+=minHeightSubCurrHeight;
            }
        }
        return sum;
    }
};
