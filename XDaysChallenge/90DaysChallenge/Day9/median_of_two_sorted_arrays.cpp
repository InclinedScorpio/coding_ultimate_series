// https://leetcode.com/problems/median-of-two-sorted-arrays/

/**
 * The naive approach of two pointers
 */`
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int biggerArrInd=0, smallerArrInd=0;
        int middleItem = (nums1.size() + nums2.size())/2;
        int medianIndFind = (nums1.size() + nums2.size()) % 2 ==0 ? middleItem - 1 : middleItem;

        // find median index
        vector<int>& biggerArr = nums1.size()>nums2.size() ? nums1 : nums2;
        vector<int>& smallerArr = nums1.size()>nums2.size() ? nums2 : nums1;

        int currMid;
        if(nums1.size()==0) currMid=nums2[0];
        if(nums2.size()==0) currMid=nums1[0];
        while(biggerArrInd<biggerArr.size() && smallerArrInd<smallerArr.size() && medianIndFind>-1) {
            if(biggerArr[biggerArrInd]>smallerArr[smallerArrInd]) {
                currMid = smallerArr[smallerArrInd];
                smallerArrInd++;
            } else {
                currMid = biggerArr[biggerArrInd];
                biggerArrInd++;
            }
            medianIndFind--;
        }

        while(medianIndFind>-1) {
            if(biggerArrInd<biggerArr.size()) {
                currMid = biggerArr[biggerArrInd];
                biggerArrInd++;
            }
            if(smallerArrInd<smallerArr.size()) {
                currMid = smallerArr[smallerArrInd];
                smallerArrInd++;
            }
            medianIndFind--;
        }

        if((nums1.size() + nums2.size()) % 2 ==0) { 
            // even, pick the next one as well
            if(biggerArrInd>=biggerArr.size() || smallerArrInd>=smallerArr.size()) {
                if(biggerArrInd<biggerArr.size()) {
                    double returnVal = currMid + biggerArr[biggerArrInd];
                    return (returnVal)/2;
                }
                if(smallerArrInd<smallerArr.size()) {
                    double returnVal = currMid + smallerArr[smallerArrInd];
                    return (returnVal)/2;
                }
            } else {
                if(biggerArr[biggerArrInd]>smallerArr[smallerArrInd]) {
                    double returnVal = currMid + smallerArr[smallerArrInd];
                    return (returnVal)/2;
                } else {
                    double returnVal = currMid + biggerArr[biggerArrInd];
                    return (returnVal)/2;
                }
            }
        } else return currMid;
        return -1;
    }
};
