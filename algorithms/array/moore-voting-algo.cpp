// https://leetcode.com/problems/majority-element/solution/

/**
 * LOGIC: Think you are jumping from one no. to another, not allowed to see behind
 * - Keep track of current no, occured again? - increase count
 * - Not the same no? decrease it's count
 * - Count reached to 0? Means there is some no which is equally counted
 * - Let's take new number as the no. you are currently standing at and counter = 1
 * - Now keep repeating and at last you will get no. which is max no of times
 * 
 * 
 * NOTE: It's not sure the no. which remains at last with some counter would be max
 * - Why? Let's take [1,2]
 * - Step1: 1-> counter = 1;
 * - Step2: 2-> counter-- so counter=0, new no=2 (counter = 1)
 * - Although 2 is currently with counter=1, it's not the max no. of times
 * 
 * - Algo can be used when we know there is definitely a significant total number which is max no. of times
 * 
 * - Alternative: use map, sort, brute force
 * 
 */ 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int myNo = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=myNo) {
                count--;
                if(count==0) {
                    myNo = nums[i];
                    count++;
                }
            }else {
                count++;
            }
        }
        return myNo;
    }
};