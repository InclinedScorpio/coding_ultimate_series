// https://leetcode.com/problems/kth-largest-element-in-an-array/

/**
 * LOGIC: We can obviously sort and return kth index - average case - O(NlogN)
 * We want to optimize average case to O(N)
 * 
 * - LOGIC: We basically want item at some index in sorted array...
 * - Think about Quick Sort, we use partitioning algo to place items to current position
 * - That means, left to placed item is all small & right to placed item is all large
 * - So if we know which index to find, we can accept one part and reject other part!
 * - This is the logic! We will be using quick sort and after placing pivot, check to pick left or right
 * 
 * COMPLEXITY: O(N) - ?? HOW ??
 * WORSE: O(N^2) - when already sorted and we want to find last index
 * BEST: O(N)- in first iteration itself pivot placed to required index(kth)
 */ 
class Solution {
public:
    int partitionerAlgo(vector<int>& arr, int left, int right) {
        int pivot = arr[left];
        int pivotIndex = left;
        
        while(left<=right) {
            while(left<=right && arr[left]<=pivot) left++;
            while(right>=left && arr[right]>pivot) right--;
            if(left<right) {
                swap(arr[left], arr[right]);
            }
        }
        swap(arr[right], arr[pivotIndex]);
        return right;
    }
    
    int quickSort(vector<int>& arr, int left, int right, int finder) {
        if(left>=right) return arr[left];
        int divider = partitionerAlgo(arr, left, right);
        if(divider==finder) return arr[finder];
        if(divider>finder) {
            return quickSort(arr, left, divider-1, finder);
        } else {
            return quickSort(arr, divider+1, right, finder);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int toFind = nums.size()-k;
        return quickSort(nums, 0, nums.size()-1, toFind);
    }
};