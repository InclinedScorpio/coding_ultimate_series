// https://leetcode.com/problems/maximum-path-quality-of-a-graph/

/**
 * 
 * Passes 58/62 test cases with TLE as isVisited can be optimized to be passed by reference
 * 
 * 
*/
class Solution {
public:
    int helper(int currNode, vector<vector<int>>& adj, vector<int>& values, int remainingTime, unordered_set<int> visited) {
        if(remainingTime<0) return -1;
        if(remainingTime==0 && currNode!=0) return -1;
        int maxSum=-1;
        bool wasAlreadyVisited=false;
        if(visited.find(currNode)!=visited.end()) {
            wasAlreadyVisited = true;
        }
        visited.insert(currNode);
        for(int i=0;i<adj[currNode].size();i++) {
            if(i!=currNode && adj[currNode][i]!=0) {
                int furtherValReceived = helper(i, adj, values, remainingTime-adj[currNode][i], visited);
                maxSum = max(maxSum, furtherValReceived);
            }
        }
        if(maxSum==-1 && currNode==0) {
            if(wasAlreadyVisited) {
                return 0;
            }
            return values[currNode];
        } else if(maxSum==-1) {
            return -1;
        } else {
            if(!wasAlreadyVisited) {
                return maxSum + values[currNode];
            } else {
                return maxSum;
            }
        }
    }



    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        // create adjacency graph
        vector<vector<int>> adj(values.size(), vector<int>(values.size(), 0));
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        unordered_set<int> visited;
        return helper(0, adj, values, maxTime, visited);
    }
};