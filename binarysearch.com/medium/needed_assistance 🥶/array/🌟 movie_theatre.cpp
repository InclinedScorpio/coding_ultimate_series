// https://binarysearch.com/problems/Movie-Theatres

/**
 * Good Question
 * LOGIC: It's a greedy problem and think greedily
 * - Initially we can pick the first movie and see when it ends
 * - For next one see if start timing is more than the end of already pushed movie
 * - If yes then the same theatre can accomodate it, if no we need a new theatre
 * - In that case, just push the new timings to the minHeap
 * 
 * - Make sure if same theatre is used, you update the top of minHeap with the new end timing
 * - Because that's what that theatre is booked until now
 * - (was confused here before) we could do above step because starting time based sorting is done
 * - and we are sure that next movie time intervals will be going to be >= the current interval time
 * 
 * COMPLEXITY: O(nlogN)
 * 
 */ 
int solve(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());
    // sorting done, now use min heap to keep smallest end time
    // if current starting is more than that smallest end time then same theatre can be used
    // Also, in that case we need to update that end time to the current end time
    // as startTime based sorting is done hence we can do above step of replacing the current time with top of minHeap as we are sure next timing coming up will definitely have more or eq time as the currents start timing.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int theatreCount=0;
    for(int i=0;i<intervals.size();i++) {
        if(minHeap.size() && minHeap.top()<=intervals[i][0]) {
            minHeap.pop();
            minHeap.push(intervals[i][1]);
        } else {
            minHeap.push(intervals[i][1]);
            theatreCount++;
        }
    }
    return theatreCount;
}