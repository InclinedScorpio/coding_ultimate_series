// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#

/**
 * LOGIC: As we will be backtracking at some point if cycle is not there, we can have another array apart from visited
 * - So as soon as we will backtrack we will set 0 to the array, but visited will still be 1, as no need coming to there as there is no way after that!
 * - Hence these 2 array approach works with DFS for detecting cycle in a directed graph!
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int ind, vector<int> adj[], vector<int>& visited, vector<int>& dfs) {
        if(visited[ind] && dfs[ind]) return true;
        if(visited[ind]) return false;
        dfs[ind]=1;
        visited[ind]=1;
        for(int i: adj[ind]) {
            bool res = helper(i, adj, visited, dfs);
            if(res) return true;
        }
        dfs[ind]=0;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> dfs(V, 0);
        for(int i=0;i<V;i++) {
            if(!visited[i])
            if(helper(i, adj, visited, dfs)) return true;
        }
        return false;
    }
};