// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

/**
 * LOGIC: The basic thinking is the one to go for
 * - We just need to pick the difference (biggest one) and multiple and return them
 * 
 * - Place to get struck is while returning, make sure to typecast and then do %modBy
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // 10^9 has to be done------------------------
        unsigned long long int modBy = pow(10, 9) + 7;
        // 10^9 has to be done------------------------
        
        // needs to be sorted in order to take the difference
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        int xMax = horizontalCuts[0], yMax = verticalCuts[0];
        
        for(int i=1;i<horizontalCuts.size();i++) {
            int res = (horizontalCuts[i] - horizontalCuts[i-1])%modBy;
            if( res > xMax) xMax = res;
        }
        for(int i=1;i<verticalCuts.size();i++) {
            int res = (verticalCuts[i] - verticalCuts[i-1])%modBy;
            if( res > yMax) yMax = res;
        }

        return ((unsigned long long)xMax * (unsigned long long)yMax)%modBy;
    }
};