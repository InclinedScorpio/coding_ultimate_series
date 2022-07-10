// https://binarysearch.com/problems/Contained-Interval

/**
 * LOGIC: Sort the intervals
 * Interval will be contained if (use scratch to understand):
 * 1) If previous starting point and current start point is same
 * 2) If previous ending point is more than or equal to current ending point
 * 
 * COMPLEXITY: O(NlogN)
 * - For sorting!
 * 
 */ 
bool solve(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]==intervals[i-1][0] || (intervals[i][1]<=intervals[i-1][1])) return true;
    }
    return false;
}