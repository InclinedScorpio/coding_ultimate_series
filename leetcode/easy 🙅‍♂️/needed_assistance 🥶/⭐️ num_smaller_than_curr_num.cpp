// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// Question:
// Given the array nums, for each nums[i] find out how many numbers in the array
//  are smaller than it. That is, for each nums[i] you have to count
//  the number of valid j's such that j != i and nums[j] < nums[i].
// 
// Return the answer in an array.
// 
// Example 1:
// 
// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]

/**
 * Solution:
 * Use DP 1D Array
 * Step 1: increment the index which no. are present
 * Step 2: use map to check multiple occurances
 * [2,5,1,6] ==> [0,1,2,2,2,3,4] ==> this will give no. smaller before an index(no.)
 **/


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int arr[500] = {0};
        vector<int> ans;
        map<int,int> mapper;

        for(int i=0;i<nums.size();i++) {
            arr[nums[i]]++;
            mapper[nums[i]]++;
        }
        
        //MAIN LOGIC!!
        for(int i=0;i<499;i++) {
            arr[i+1]+=arr[i];
        }
        
        for(int i=0;i<nums.size();i++) {
            int num;
            if(mapper[nums[i]]<= 1) {
                num=0;
            }else {
                num = mapper[nums[i]]-1;
            }
            ans.push_back(arr[nums[i]]-1-num);
        }
        
        return ans;
    }
};