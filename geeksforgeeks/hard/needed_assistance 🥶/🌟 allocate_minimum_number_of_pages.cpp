// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/#

/**
 * LOGIC: Already same question is done before and logic is mentioned there
 * 
 * - The major logic is that we can have a range where our answer will lie
 * - Hence we can make use of binary search to search that number
 * 
 * - We will pick number in range (this num is  maximum numbers which can be allocated to all the students) 
 * 
 * LOGIC: O(NlogN)
 */ 
class Solution {
    public:
    
    bool checkIfMidPagesCanBeAllocatedToEveryone(int A[], int N, int M, int mid) {
        
        int students=1, pagesCount=0;
        for(int i=0;i<N;i++) {
            pagesCount+=A[i];
            if(pagesCount>mid) {
                students++;
                pagesCount=A[i];
            }
            if(students>M) return false;
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int left = A[N-1];
        int right=0;
        for(int i=0;i<N;i++) right+=A[i];
        
        int result=-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(checkIfMidPagesCanBeAllocatedToEveryone(A, N, M, mid)) {
                result = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return result;
    }
};