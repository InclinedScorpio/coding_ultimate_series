// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

/**
 * Logic: It's a interval question
 * After sorting using the end point...
 * .. we need to start picking each intervals from the first and not end
 * ... as picking from first and comparing will give us result in minimum arrows
 * 
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y){
                return y[1]>x[1];
        });

        int result=0;
        for(int i=0;i<points.size();) {
            int currInd=i+1;
            result++;
            while(currInd<points.size() && points[currInd][0]<=points[i][1]) {
                currInd++;
            }
            i=currInd;
        }
        return result;
    }
};
