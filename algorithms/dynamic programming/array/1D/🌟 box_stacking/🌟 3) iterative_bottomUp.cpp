/**
 * QUESTION: Stack boxes on top of each other
 * - The one above should have dimension strictly less than below one
 * - Find the maximum height possible
 * 
 * LOGIC: Similar to recursion
 * - Here dp is used to memoize data already calculated
 * 
 * COMPLEXITY: O(n*n)
 * 
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
#include<algorithm>

using namespace std;

bool comparator(vector<int> a, vector<int> b) {
    return a[2]<b[2];
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
    sort(boxes.begin(), boxes.end(), comparator);
    vector<int> dp(boxes.size(), 0);
    int maxVal;
    for(int i=0;i<boxes.size();i++) {
        int maxHeight=0;
        for(int j=0;j<i;j++) {
            if(boxes[j][0]<boxes[i][0] &&
            boxes[j][1]<boxes[i][1] &&
            boxes[j][2]<boxes[i][2]) {
                maxHeight = max(maxHeight, dp[j]);
            }
        }
        dp[i]=boxes[i][2]+maxHeight;
    }
    cout<<*max_element(dp.begin(), dp.end());
}