/**
 * 
 * NOTE: Q can be done differently as well (taking index from N and then coming all the back to 0)
 * (here from 0 to N is done)
 * 
 * QUESTION: Height of pole are given
 * - Frog can jump to next or next of next only
 * - The price he pays for jump is difference in height
 * - Find the minimum price he needs to pay to reach end
 * 
 * 
 * LOGIC: As multiple ways are possible - this is clear case of recursion
 * - Hence we try to make a tree diagram of how to approach it
 * F(N) = min( F(N-1) + height[i]-height[i-1], F(N-2) + height[i] - height[i-2])
 * 
 * - 1) Doing raw recursion to get required result
 * 
 * COMPLEXITY: O(2^N)
 * 
 * - OPtimization can be done as overlapping subproblems exists (while forming tree we can check)
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

using namespace std;

int findMinimumJump(vector<int> heights, int i=0) {
    if(i==heights.size()-1) return 0;
    int left, right=INT_MAX;
    left = findMinimumJump(heights, i+1) + abs(heights[i] - heights[i+1]);
    if(i < heights.size()-2)
        right = findMinimumJump(heights, i+2) + abs(heights[i] - heights[i+2]);
    return min(left, right);
}

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    cout<<findMinimumJump(heights);
}
