// https://leetcode.com/problems/non-overlapping-intervals


/**
 * 
 * Understanding of comparator function with sorting
 * 
 * Sort only with ending time of intervals! Don't care of starting time
 * 
 * Keep the ending time always with you with the interval recently selected
 * 
 * First interval will always be choosen
 * 
 * QUESTION similar to maximum numer of meetings in a room...
 * 
 */
class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>&b) {
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(!intervals.size()) return 0;
        sort(intervals.begin(), intervals.end(), comparator);
        int result=1;
        int lastEndingInterval = intervals[0][1];

        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]<lastEndingInterval) {
            } else {
                lastEndingInterval = intervals[i][1];
                result++;
            }
        }
        return intervals.size() - result;
    }
};
