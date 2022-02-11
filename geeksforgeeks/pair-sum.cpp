// https://practice.geeksforgeeks.org/problems/key-pair5616/1/

/**
 * LOGIC: Here Two Pointer Method is implemented - O(N)
 * Two Pointer Method requires the elements to be sorted.
 * 
 * BETTERWAY: Use HashMap to store the elements as you move forward.
 * - and keep checking [variable - currentNo.]
 */ 
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr, arr+n); // O(NLogN)
	    int left=0,right=n-1;
	    while(left<right) { // O(N)
	        if(arr[left]+arr[right]==x) {
	            return true;
	        }else if((arr[left]+arr[right])<x) {
	            left = left+1;
	        }else {
	            right=right-1;
	        }
	    }
	    return false;
	}
};
