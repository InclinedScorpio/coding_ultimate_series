// https://binarysearch.com/problems/Find-the-Largest-Number-in-a-Rotated-List

/**
 * LOGIC: logN complexity is given in question
 * - Also it's kind of sorted
 * - Hence, clear case of Binary Search
 * 
 * - We need to find the pivot point in this binary search
 * 
 * COMPLEXITY: O(logN)
 *
 */ 
int solve(vector<int>& arr) {
    if(arr[0]<=arr[arr.size()-1]) return arr[arr.size()-1];

    // bs to check pivot point
    int left=0, right = arr.size()-1;
    while(left<=right) {
        int mid = (left+right)/2;
        if(arr[mid]>arr[mid+1]) return arr[mid];
        if(arr[mid-1]>arr[mid]) return arr[mid-1];
        if(arr[mid]>arr[left]) {
            left=mid+1;
        } else {
            right=mid-1;
        }
    }
    return -1;
}