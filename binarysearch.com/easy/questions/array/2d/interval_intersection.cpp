// https://binarysearch.com/problems/Interval-Intersection

vector<int> solve(vector<vector<int>>& intervals) {
    int currMin=INT_MAX;
    int currMax=INT_MIN;
    for(int i=0;i<intervals.size();i++) {
        currMax = max(currMax, intervals[i][0]);
        currMin = min(currMin, intervals[i][1]);
    }
    return {currMax, currMin};
}