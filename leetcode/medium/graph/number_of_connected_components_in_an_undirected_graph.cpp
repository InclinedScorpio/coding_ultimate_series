// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

/**
 * LOGIC: Basic dfs in a graph problem
 *
 */
class Solution {
public:
    
    void helper(vector<vector<int>>& adj, int node, vector<int>& isVisited) {
        if(isVisited[node]!=0) return;
        isVisited[node]=1;
        for(int i: adj[node]) {
            helper(adj, i, isVisited);
        }
    }
    
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> isVisited(n, 0);
        
        int components=0;
        for(int i=0;i<n;i++) {
            if(isVisited[i]==0) components++;
            helper(adj, i, isVisited);
        }
        
        return components;
    }
};