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
 * COMPLEXITY: O(N) - ?? HOW ?? 👇
 * - focus on partitioning algo - we are calling it only for one half
 * - In average case /2 will be happening so let's sum all the time
 * N + N/2 + n/4 + N/8  . . . . . + 4 + 2 + 1 
 * Let's take N as some power of 2(for ease of operation) - 2^k
 * 2^k + 2^k-1 + 2^k-2 + .... + 1
 * - This is geometric series
 * where a=2^k, r=1/2, n=k+1 -> keep in formula of G.S
 * replace 2^k with N 
 * - Complexity - O(2N-1) ~ O(N)
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