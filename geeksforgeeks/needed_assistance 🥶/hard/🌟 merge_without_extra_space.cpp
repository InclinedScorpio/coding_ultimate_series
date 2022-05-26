// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#

/**
 * LOGIC: Little complicated but easy
 * - 2 sorted arrays are given we need to sort then as if both were one, So...
 * - We are sure that first array will contain all the smallest item which can be present in both array
 * - So, at first sight, if I see the last item of first array (greatest)...
 * - And the 1st item (smallest) of second array and verify if 2nd arrays smallest is smaller than greatest of 1st array?
 * - If yes, that means it's sure that our final result will have the smallest of 2nd array item lying somewhere in first array
 * 
 * - Now, let's swap it. Now what to do? Now let's move to 2nd item of 2nd array...
 * - Should we compare it again with last item of 1st arry? No! because we are sure that will be smaller (because 2nd array is sorted)
 * - Hence, we will check 2nd last item of 1st array and again check if 2nd array's item is smaller than 1st item
 * - If yes then swap and keep doing the same
 * 
 * COMPLEXITY: O(NlogM + MLogN + M + N)
 * SPACE: O(1)
 */ 
class Solution{
        public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i = n-1, j=0;
            while(i>=0 && j<=m-1 && arr1[i]>arr2[j]) {
                // cout<<"here ";
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        }
};