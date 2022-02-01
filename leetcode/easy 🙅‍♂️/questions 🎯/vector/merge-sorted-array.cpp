// https://leetcode.com/problems/merge-sorted-array/

/**
 * Important to understand vector operations like:
 * 1. insert
 * 2. erase
 * 3. push_back
 * 
 */ 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n==0) {
            return;
        }
        
        nums1.erase(nums1.begin()+m, nums1.end());
        
        int copyIndex=0;
        // iterate on num1
        for(int i=0;i<m+n;i++) {
            if(i==nums1.size()) {
                nums1.insert(nums1.begin()+i, nums2[copyIndex++]);
                continue;
            }
            if( copyIndex<n && ( nums1[i]>nums2[copyIndex])) {
                nums1.insert(nums1.begin()+i, nums2[copyIndex++]);
            }
        }
        nums1.erase(nums1.begin()+(m+n), nums1.end());    
    }
};
