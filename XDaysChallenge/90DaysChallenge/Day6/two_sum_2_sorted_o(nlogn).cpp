// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/**
 * O(nlogN) solution - binary search
 * - We can optimize it by using two pointer approach
 */
class Solution {
public:
    int binarySearchMe(vector<int>& numbers, int toFind, int left) {
        int leftForThisCall = left;
        int right = numbers.size()-1;
        int mid = (right + left)/2;
        while(left>=leftForThisCall && left<=right && numbers[mid]!=toFind) {
            if(numbers[mid]>toFind) {
                right = (mid) - 1;
            } else {
                left = (mid) + 1;
            }
            mid = (right + left)/2;
        }
        if(left>=leftForThisCall && left<=right && numbers[mid]==toFind) {
            return mid;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {

        for(int i=0;i<numbers.size()-1;i++) {
            int result = binarySearchMe(numbers, (target - numbers[i]), i+1);
            if(result!=-1) { // returning -1 for no result
                return {i+1, result+1};
            }
        }
        return {-1, -1};// wont reach here
    }
};