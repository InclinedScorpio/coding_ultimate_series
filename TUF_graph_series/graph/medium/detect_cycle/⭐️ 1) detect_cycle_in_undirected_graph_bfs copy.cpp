// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

/**
 * LOGIC: Done using BFS Logic
 * - Use visited array to keep track of already visited nodes
 * - BUT! Also make sure to note the node from where you just came, so use queue<pair<int, int>> store;
 * 
 * COMPLEXITY: O(Nodes + Edges)
 * 
 */ 
class Solution {
      public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int index, vector<int> adj[], vector<int>& visited) {
        // Code here
        queue<pair<int, int>> store;
        store.push({index, -1});
        visited[index]=1;
        while(!store.empty()) {
            pair<int, int> node = store.front();
            store.pop();
            for(int i: adj[node.first]) {
                if(i==node.second) continue;
                if(visited[i]) return true;
                visited[i]=1;
                store.push({i, node.first});
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<pair<int, int>> store;
        vector<int> visited(V, 0);
        for(int i=0;i<V;i++) {
            if(!visited[i] && checkCycle(i, adj, visited)) return true;
        }
        return false;
    }
};
