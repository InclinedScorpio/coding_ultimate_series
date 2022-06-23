// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#


/**
 * LOGIC: Problem is similar to finding median of two sorted arrays
 * - There we were first counting how many numbers will lie before the median and then from both array trying to get those no of items in left
 * 
 * - Similar to that we have to do here - it's just that number of items in the left (k) is already given in question
 * 
 * 1) We will pick the smaller array and implement binary search in that
 * 2) Binary search will just place the limit on first array and remaining items will be picked from second array
 * 3) But this limit has to be checked if this is fine or not! How check? - Just see if sm1<lg2  and lg1<sm2
 * - Meaning check if the numbers on the left range are smaller than the ones in the right or not
 * - Because that's how we are literally getting the limit if we had both arrays as one.
 * 4) Once we get just return the max of it - as that's the kth number
 * 
 * COMPLEXITY: O(log(min(M, N)))
 * SPACE: O(1)
 * 
 */ 
class Solution {
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // arr2 must always be smaller
        if(n<m) return kthElement(arr2, arr1, m, n, k);
        
        int sm1, sm2, lg1, lg2;
        int left= 0, right=m;
        while(left<=right) {
            int mid = left + (right-left)/2;
            int lgIndex=k-mid;
            if(lgIndex>n) {
                left=mid+1;
                continue;
            }
            if(lgIndex<0) {
                right=mid-1;
                continue;
            }
            sm1 = mid==0 ? INT_MIN: arr2[mid-1];
            sm2 = mid==m ? INT_MAX : arr2[mid];
            lg1 = lgIndex==0 ? INT_MIN: arr1[lgIndex-1];
            lg2 = lgIndex==n ? INT_MAX: arr1[lgIndex];
            
            if(sm1<=lg2 && lg1<=sm2) {
                return max(sm1, lg1); 
            } else if(sm1>lg2) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
};
