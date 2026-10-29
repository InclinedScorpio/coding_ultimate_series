// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        int ind=0;

        sort(intervals.begin(), intervals.end());
        int first=intervals[0][0], second=intervals[0][1];

        while(ind+1<intervals.size()) {
            if(intervals[ind+1][0]<=second) {
                second=max(second, intervals[ind+1][1]);
                ind++;
            } else {
                output.push_back({first, second});
                ind++;
                first=intervals[ind][0];
                second=intervals[ind][1];
            }
        }
        output.push_back({first, second});
        return output;

        
    }
};
