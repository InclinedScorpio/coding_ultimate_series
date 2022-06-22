// https://leetcode.com/problems/median-of-two-sorted-arrays/

/**
 * 
 * LOGIC: Main logic is that before medium we have n/2 numbers
 * - Same can be implemented here as we can find those n/2 number by taking x items from array 1 and y from array 2
 * - Those items will form those n/2 - but we need to find the limit which we need to take in both these arrays!
 * 
 * WHERE_I_GOT_CONFUSED: The index where we are making cut
 * - If we are making cut at 0 that means 0th index is sm2 or lg2 and sm1/lg1 will be INT_MIN (INT_MIN because so that while comparing it's satisifed)
 * - Also if index == size of array that means, last item is our sm1/lg1 and sm2/lg2 is our INT_MAX
 * - Also for all other index, index means sm2/lg2 (because just before that index we are cutting) - hence previous index is sm1/lg1
 * 
 * COMPLEXITY: O(log(M+N))
 * 
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums2 must be always smaller
        if(nums1.size()<nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left=0, right = nums2.size();
        int totalOnLeft = (nums1.size() + nums2.size() + 1) / 2;

        bool areItemsEven = true;
        if((nums1.size() + nums2.size()) & 1) areItemsEven = false;
        
        while(left<=right) {
            int mid = (left+right)/2;
            int lg1, sm1, lg2, sm2;
            
            // if one array has mid items then other will have...
            int lgItems = totalOnLeft-mid;
            // index 0 means, no item is taken into account
            // index == size means, all items are taken into account
            // hence we need to take care both these conditions
            if(mid==0) {
                sm1=INT_MIN;
                sm2=nums2.size() ? nums2[0]: INT_MAX;
            } else if(mid==nums2.size()) {
                sm1=nums2[nums2.size()-1];
                sm2=INT_MAX;
            } else {
                sm1=nums2[mid-1];
                sm2=nums2[mid];
            }
            //lgItems can also have similar edge cases as discussed above
            if(lgItems==0) {
                lg1 = INT_MIN;
                lg2=nums1.size() ? nums1[0]: INT_MAX;
            } else if(lgItems==nums1.size()) {
                lg1=nums1[nums1.size()-1];
                lg2=INT_MAX;
            } else {
                lg1 = nums1[lgItems-1];
                lg2 = nums1[lgItems];
            }
            
            if(sm1<=lg2 && lg1<=sm2) {
                if(areItemsEven) {
                    return (double)((double)max(lg1, sm1) + min(lg2, sm2))/2.0;
                } 
                return (double)max(lg1, sm1);
            } else if(sm1>lg2) right=mid-1;
            else left = mid+1;
        }
        return -1;
    }
};