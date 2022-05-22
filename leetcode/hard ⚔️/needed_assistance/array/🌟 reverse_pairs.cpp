// https://leetcode.com/problems/reverse-pairs/

/**
 * LOGIC: Q Similar to inversion count
 * - Here we are required to reduce complexity from O(N^2) to O(NlogN)
 * - Hence we go for merge sort
 * - As there we have 2 sorted arrays & there we can easily calculate our requirement
 * i.e i<j && nums[i]>2*nums[j]
 * - As both arrays are sorted
 * - We get this advantage that we can just check the requirement in those array in O(N)
 * 
 * - As once we know for nums[A]>2*nums[B]
 * - We can be sure for all nums after A, it will be satisfied
 * 
 * COMPLEXITY: O(NlogN) + O(N) + O(N)
 * - One O(N) is for checkReversePairs and other for merge
 * 
 * 
 */ 

void merge(vector<int>& nums, int left, int mid, int right) {
    int leftSide=left;
    int rightSide=mid+1;
    vector<int> store;
    while(leftSide<=mid && rightSide<=right) {
        if(nums[leftSide]>nums[rightSide]) {
            store.push_back(nums[rightSide]);
            rightSide++;
        } else {
            store.push_back(nums[leftSide]);
            leftSide++;
        }
    }
    while(leftSide<=mid) {
        store.push_back(nums[leftSide]);
        leftSide++;
    }
    while(rightSide<=right) {
        store.push_back(nums[rightSide]);
        rightSide++;
    }
    int index=0;
    for(int i=left;i<=right;i++) {
        nums[i]=store[index];
        index++;
    }
}

// will take O(N)
int checkReversePairs(vector<int>& nums, int left, int mid, int right) {
    int counter=0;
    int leftSide = left;
    int rightSide = mid+1;
    
    // main logic (keep shifting j to right & at last calculate)
    for(;leftSide<=mid;leftSide++) {
        while(rightSide<=right && nums[leftSide]>2LL*nums[rightSide]) rightSide++;
        counter+=(rightSide-(mid+1));
    }
    return counter;
}

int mergeSort(vector<int>&nums, int left, int right) {
    if(left>=right) return 0;
    int mid = (left+right)/2;
    
    int leftCounter = mergeSort(nums, left, mid);
    int rightCounter = mergeSort(nums, mid+1, right);
    int counter = checkReversePairs(nums, left, mid, right);
    merge(nums, left, mid, right);
    return leftCounter+ rightCounter+ counter;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums, 0, nums.size()-1);
    }
};