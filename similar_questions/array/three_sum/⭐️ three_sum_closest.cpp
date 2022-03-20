// https://leetcode.com/problems/3sum-closest/

/**
 * LOGIC: Similar to three_Sum problem
 * - Keeping one index fix and taking 2 ptr approach for rest 
 * - But for doing this sorting will be required
 * - Once sorting is done, keep traversing which doing 2 pointer approach for each index
 * - This will result in nearest value for each index
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int totalSize = nums.size()-1;
        sort(nums.begin(), nums.end());
        int smallestValue=INT_MAX;
        int sum;
        for(int i=0;i<nums.size()-2;i++) {
            int left=i+1, right=nums.size()-1;            
            while(left<right) {
                int currSum = abs(target-(nums[i] + nums[left] + nums[right]));
                if(currSum < smallestValue) {
                    smallestValue = currSum;
                    sum=nums[i] + nums[left] + nums[right];
                }
                int sum3 = (nums[i] + nums[left] + nums[right]); 
                if(sum3>target) right--;
                else left++;
            }
        }
        return sum;
    }
};