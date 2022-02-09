// https://binarysearch.com/problems/Intervals-Intersecting-at-Point

int solve(vector<vector<int>>& intervals, int point) {
    int res=0;
    for(int i=0;i<intervals.size();i++) {
        int left=intervals[i][0];
        int right=intervals[i][1];
        if(left<=point && right>=point) {
            res++;
        }
    }
    return res;
}