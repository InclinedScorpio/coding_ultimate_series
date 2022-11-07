// https://leetcode.com/problems/minimum-time-visiting-all-points/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int steps=0;
        for(int i=0;i<points.size()-1;i++) {
            
            // pick the point
            int currX = points[i][0];
            int currY = points[i][1];
            int nextX= points[i+1][0];
            int nextY= points[i+1][1];
            steps+=max(abs(currX-nextX), abs(currY-nextY));
        }
        return steps;
    }
};