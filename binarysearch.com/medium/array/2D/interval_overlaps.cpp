// https://binarysearch.com/problems/Interval-Overlaps

/**
 * Nice Question
 *  LOGIC: Both the interval list are given in ascending order
 * - Hence we can make use of it
 * - Don't do sorting and all without thinking about the question for 5 minutes
 * - We were required to just use 2 pointers and question is completed
 * - Just 2 pointers, and if else to include the intervals
 * 
 * COMPLEXITY: O(M+N)
 * 
 */
vector<vector<int>> solve(vector<vector<int>>& l0, vector<vector<int>>& l1) {
    int i=0, j=0;
    vector<vector<int>> result;
    while(i<l0.size() && j<l1.size()) {
        if(l0[i][0]>l1[j][1]) {
            j++; continue;
        }
        if(l0[i][1]<l1[j][0]) {
            i++; continue;
        }
        if(l0[i][1]==l1[j][0]) {
            result.push_back({l0[i][1], l0[i][1]});
            if(l0[i][1] > l1[j][1]) {
                j++;
            } else {
                i++;
            }
             continue;
        }
        // means exists
        result.push_back({max(l0[i][0], l1[j][0]), min(l0[i][1], l1[j][1])});
        if(l0[i][1] > l1[j][1]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}