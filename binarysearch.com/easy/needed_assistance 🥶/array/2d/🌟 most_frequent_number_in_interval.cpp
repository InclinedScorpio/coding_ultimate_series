// https://binarysearch.com/problems/Most-Frequent-Number-in-Intervals

/**
 * LOGIC: First think of brute force - we can use a big array to flag current overlapped range using int
 * - But that won't be optimized and will take lot of space and time as for 1-10 we need to go from 1-10 incrementing number by one
 * 
 * OPTIMIZED:
 * - We can use a map(keeps sorted using key) to store where to increment and decrement
 * - Means if range is from 1-10 we will store 1:+1 & 10:-1
 * - This will help us to keep count of currNo. of range
 * - And from that we can find the maximum one
 * - *NOTE: It will be always the starting point of any range (as minimum needs to be given if similar) 
 * 
 * COMPLEXITY: O(NlogN)
 */
int solve(vector<vector<int>>& intervals) {
    map<int, int> store;
    for(int i=0;i<intervals.size();i++) {
        store[intervals[i][0]]++;
        store[intervals[i][1]+1]--;
    }
    int currMax=INT_MIN;
    int currMaxIndex=-1;
    int currLocal=0;
    for(const auto& s: store) {
        currLocal+=s.second;
        if(currLocal>currMax) {
            currMax=currLocal;
            currMaxIndex=s.first;
        }
    }
    return currMaxIndex;
}
