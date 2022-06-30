// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

/**
 * LOGIC: Dfs approach is similar to bfs (checkout bfs first)
 * - Here we will use recursion rather than stack
 * - Keep check of parent to see from where the control came
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 
class Solution {
  public:

    bool dfs(int V, int ind, int parent, vector<int>& visited, vector<int> adj[], vector<int>& result) {
        visited[ind]=1; 
        result.push_back(ind);
        for(int i: adj[ind]) {
            if(visited[i] && i!=parent) return true;
            if(!visited[i] && dfs(V, i, ind, visited, adj, result)) 
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> result(V);
        for(int i=0;i<V;i++) {
            if(!visited[i] && dfs(V, i, -1, visited, adj, result)) {
                return true;
            }
        }
        return false;
    }
};

