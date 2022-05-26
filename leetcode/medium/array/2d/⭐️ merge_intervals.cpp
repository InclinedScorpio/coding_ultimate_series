// https://leetcode.com/problems/merge-intervals/

/**
 * LOGIC: First step is clearly to sort it
 * - Now we need to keep checking if the next one is under the current one
 * - If yes, then include it in current ongoing streak and now pick next one and check again
 * - Once we find a line outside current range, first add current streak then start next streak
 * 
 * COMPLEXITY: O(NlogN)
 * SPACE: O(N)
 */ 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        
        for(int i=0;i<intervals.size();) {
            int j=i+1;
            int start = i;
            int maxLast = intervals[i][1];
            for(;j<intervals.size();j++) {
                if(maxLast>=intervals[j][0]) {
                    if(intervals[j][1]>maxLast) {
                        maxLast = intervals[j][1];
                    }
                    i=j;
                    continue;
                }
                j--; // as curr index doesn't comply, so do j-1
                break;
            }
            if(j==intervals.size()) j--; // if j has overshooten
            result.push_back({intervals[start][0], maxLast});
            i=j+1;
        }
        return result;
    }
};