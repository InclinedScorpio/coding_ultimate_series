https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#


/**
 * LOGIC: Logic is to understand how to go from O(N^2) to O(nlogn)
 * - Only logic is to understand it's a modification of merge sort problem
 * - In merge sort also we take left, right part and then compare them
 * 
 * - So while comparing we can also see if left is > than right index
 * - If yes then in left from that index all other will also be > right index... why ?
 * - Because left & right are sorted (Merge sort starts from single item both side - already sorted)
 * - Hence we are optimizing the comparisons to the right as now we don't need to check all left once
 * 
 * - Make sure you are sorting the array as well along so that optimizing(if left>right - then all other items from left ind to further left part will also be > than right index) can be done 
 * ☝️ point to note! (Main logic)
 * 
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    long long int countInversion(long long arr[], long long left, long long right){
        long long mid = (left+right)/2;
        long long i=left, j=mid+1;
        long long int result = 0;
        vector<long long> store;
        while(i<=mid && j<=right) {
            if(arr[i] > arr[j]) {
                result += (mid-i+1);
                store.push_back(arr[j]);
                j++;
            } else {
                store.push_back(arr[i]);
                i++;
            }
        }
        
        while(i<=mid) {
            store.push_back(arr[i]);
            i++;
        }
        
        while(j<=right) {
            store.push_back(arr[j]);
            j++;
        }
        
        long long index=0;
        for(long long i=left;i<=right;i++) {
            arr[i] = store[index++];
        }
        
        return result;
    }
    
    
    long long int divideArr(long long arr[], long long left, long long right) {
        if(left>=right) return 0;
        long long mid = (left+right)/2;
        long long int leftRes = divideArr(arr, left, mid);
        long long int rightRes = divideArr(arr, mid+1, right);
        return leftRes + rightRes + countInversion(arr, left, right);
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        return divideArr(arr, 0, N-1);
    }

};