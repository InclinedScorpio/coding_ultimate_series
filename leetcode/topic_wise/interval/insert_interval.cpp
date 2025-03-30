// https://leetcode.com/problems/insert-interval/description

/**
 * Greedy problem
 * If you can think of greedy, it's simple to write - time taking - lot of edge cases.
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int start = newInterval[0];
        int end = newInterval[1];
        int restOfInd=-1;
        if(intervals.size()==0) return {newInterval};
        for(int i=0;i<intervals.size();i++) {
            if(start<=intervals[i][1]) {
                // we found the interval to be added
                if(end<intervals[i][0]) {
                    // interval got fit in between
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                    restOfInd=i+1;
                    break;
                } else {
                    // it wont fit
                    start = min(intervals[i][0], start);
                    int ind = i;
                    while(ind<intervals.size()) {
                        if(end<intervals[ind][0]) {
                            result.push_back({start, end});
                            restOfInd=ind;
                            break;
                        } else {
                            if(end<=intervals[ind][1]) {
                                end = max(end, intervals[ind][1]);
                                result.push_back({start, end});
                                restOfInd=ind+1;
                                break;
                            }
                        }
                        ++ind;
                    }
                    if(restOfInd!=-1) {
                        break;
                    };
                    // means complete done
                    result.push_back({start, end});
                    return result;
                }
            } else {
                result.push_back(intervals[i]);
            }
        }
        if(restOfInd==-1) {
            result.push_back(newInterval);
            return result;
        }
        for(int i=restOfInd;i<intervals.size();i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};
