/**
 * QUESTION: Stack boxes on top of each other
 * - The one above should have dimension strictly less than below one
 * - Find the maximum height possible
 * 
 * LOGIC: As dimensions are required to be checked & height needs to be max
 * - Let's arrange boxes on basis of height first
 * - now recursively check from each index to 0th what all can be stack above
 * - We clearly see there are lots of overlapping subproblems as this is basic recursion
 * - Should use DP in order to memoize it
 * 
 * COMPLEXITY: O(n^n)
 * 
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

bool comparator(vector<int> a, vector<int> b) {
    return a[2]<b[2];
}

int helper(vector<vector<int>>& boxes, int ind=0) {
    int maxHeight=0;
    int sumHeight=0;
    for(int i=0;i<ind;i++) {
        if(boxes[i][0]<boxes[ind][0] && boxes[i][1]<boxes[ind][1] &&
            boxes[i][2]<boxes[ind][2]) {
            int height = helper(boxes, i);
            maxHeight = max(maxHeight, height);
        }
    }
    return maxHeight + boxes[ind][2];
}

int maximumHeightOnStacking(vector<vector<int>> boxes) {
    sort(boxes.begin(), boxes.end(), comparator);
    int maxValue=INT_MIN;
    for(int i=0;i<boxes.size();i++) {
        maxValue = max(maxValue, helper(boxes, i));
    }
    return maxValue;
}

int main() {
    vector<vector<int>> boxes = {
        {2, 1, 2}, 
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5}
    };
    cout<<maximumHeightOnStacking(boxes);
}