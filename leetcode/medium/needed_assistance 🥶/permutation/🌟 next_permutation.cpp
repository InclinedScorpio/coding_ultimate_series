// https://leetcode.com/problems/next-permutation/

/**
 * LOGIC: Just have to think the right way using scratch
 * - [1,2,3] -> next permutation is what?
 * - [1, 3, 2] -> how we did it ?
 * - Obviously found from right when index is smaller than prev
 * - Means the prev needs to be swapped from some number from right
 * - But which? - The one which is just greater!
 * 
 * - After swapping, we need to make sure the numbers after '3' are sorted
 * - Why?
 * - [1,3,2] -> let's find next permute
 * - index is 1st one where prev index item is smaller
 * - now we know 1 needs to be swapped for sure
 * - As rest on right are already in decreasing order and swapping won't help
 * - ... getting the next greater permute
 * - Hence, we swap 1 with.... ?
 * - The one which is just greater -> '2'
 * - So swap '1' and '2 -> [2,3,1]
 * - But this it NOT THE NEXT PERMUTE WHY ?
 * - Because right now have the next greater num starting from '2'
 * - But the num on right of '2' must be sored ascending wise
 * - So that it's truly next permute! so sort items after '2'
 * - [2,1,3] -> :) Next Permute found! That's all
 * 
 * COMPLEXITY: O(NlogN)
 * If you look closely after swapping rather than sorting, we can go for reversing items after '2'
 * - Because logically they will be in decending order, and we want it to be increasing order(we want next permute)
 * - O(N) COMPLEXITY in that case!
 * 
 */ 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //(1) finding the num which needs to be swapped from some num to right
        // eg. [1,3,2] -> next num is '1' as 3>2 and 1<3 -> means for '3' or '2'...
        // ...swapping from right won't help as already there are decresingly sorted
        int nextNumToBeSwapped;
        int indexOfNextNumToBeSwapped;
        bool isNextPermuteExists = false;
        for(int i=nums.size()-1;i>=1;i--) {
            if(nums[i]>nums[i-1]) {
                nextNumToBeSwapped = nums[i-1];
                indexOfNextNumToBeSwapped = i-1;
                isNextPermuteExists = true;
                break;
            }
        }
        
        if(!isNextPermuteExists) { //(-) no next Permute exists!
            sort(nums.begin(), nums.end());
            return;
        }
        
        // now that '1' needs to be swapped with some number from right
        // let's find that number. The number which is just greater on right is the one
        // Make sure after finding and swapping, sorting is done
        // Why sorting? The number which is swapped at place of '1' is fine
        //But the rest on the right are not correct as [2,3,1] is not the nextPermute
        // Rather [2,1,3] is the right one! After this [2,3,1] is the next Permute
        int minGreaterElement = INT_MAX;
        int indexOfMinGreaterElement;
        for(int i=nums.size()-1;i>indexOfNextNumToBeSwapped;i--) {
            if(nums[i]>nextNumToBeSwapped && nums[i]<minGreaterElement) {
                minGreaterElement = nums[i];
                indexOfMinGreaterElement = i;
            }
        }
        
        swap(nums[indexOfNextNumToBeSwapped], nums[indexOfMinGreaterElement]);
        sort(nums.begin()+indexOfNextNumToBeSwapped+1, nums.end());
        return;
    }
};