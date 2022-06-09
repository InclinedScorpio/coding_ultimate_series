// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

/**
 * LOGIC: Focus on the ending time
 * - Take the bar which has ending time at the earliest
 * - Find the next one which ends at earliest and has starting point after current bar
 * - Keep checking this and increase counter
 * 
 * COMPLEXITY: O(nlogn)
 * SPACE: O(N)
 * 
 */ 
class Solution {
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> bars;
        for(int i=0;i<n;i++) {
            bars.push_back({end[i], start[i]});
        }
        
        sort(bars.begin(), bars.end());
        
        int sum=1, currMin=bars[0].first;
        for(int i=1;i<n;i++) {
            if(bars[i].second>currMin) {
                sum++;
                currMin = bars[i].first;
            }
        }
        
        return sum;
    }
};
