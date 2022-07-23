// https://leetcode.com/problems/critical-connections-in-a-network/

/**
 * LOGIC: Problem is simple, it's important to understand the approach
 * - We are required to find the bridge, if broken, no. of components will increase
 * 
 * - Now what we can do is assign cost to each node and increase as we go to next node
 * - Once reached visited node, we can return the cost from there
 * - And see if the current node has cost more than that or less than that
 * 
 * - If cost more than that (the next node) that means the path has some alternative and breaking the bridge will create no effect to no. of components
 * - But if cost less than that, that means IT'S A BRIDGE !!
 * 
 * - Hence we need to keep record of cost array as well as visited array
 * NOTE: Make sure not to go back to node from where you are coming, just return the cost to it so it can compare with it's current value
 * 
 */ 
class Solution {
public:
    int findBridges(int n, int ind, vector<int> adj[], vector<vector<int>>& bridges, vector<bool>& visited, vector<int>& cost, int& currentCost, int comingFrom) {
        if(visited[ind]) return cost[ind];
        
        visited[ind] = true;
        cost[ind] = currentCost;
        int minCost = currentCost;
        for(int i=0;i<adj[ind].size();i++) {
            if(adj[ind][i]==comingFrom) continue;
            currentCost++;
            int currCost = findBridges(n, adj[ind][i], adj, bridges, visited, cost, currentCost, ind);
            if(currCost>cost[ind])
                bridges.push_back({ind, adj[ind][i]});
            else minCost = min(minCost, currCost);
        }
        cost[ind] = minCost;
        return minCost;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        // create adjacency list
        for(int i=0;i<connections.size();i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> bridges;
        vector<bool> visited(n, false);
        vector<int> cost(n, 0);
        int currentCost = 0;
        findBridges(n, 0, adj, bridges, visited, cost, currentCost, -1);
        return bridges;
    }
};