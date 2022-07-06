// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

/**
 * LOGIC: In dfs, it was easy to use isVisited and dfs array to check if we are coming back to already visited and non reversed back node
 * - But here as we need to do BFS, that approach can't be done
 * 
 * - We already know how to do Topological Sorting using bfs
 * - And in that we find indegree and then form the topological sort
 * - hence, while completeting indegree and forming the sort, we can check if all indegree are returned back to 0, which they should in case of DAG
 * - But if all indegree aren't changed back to 0 that means there is some cycle formed
 * - because in scratch try!- for cycle there won't be any more 0 there and hence it will be bfs will stop!
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 
class Solution {
  public:
  
    void inDegreeFind(vector<int> adj[], int ind, vector<int>& inDegree, vector<int>& isVisited) {
        if(isVisited[ind]) return;
        queue<int> q;
        q.push(ind);
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            if(isVisited[front]) continue;
            
            isVisited[front]=1;
            for(int i: adj[front]) {
                inDegree[i]+=1;
                q.push(i);
            }
        }
    }
    
    void topologicalSortBfs(int V, vector<int> adj[], vector<int>& inDegree) {
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(!inDegree[i]) q.push(i);
        }
        // all zeros in
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(int i: adj[front]) {
                inDegree[i]-=1;
                if(inDegree[i]==0) q.push(i);
            }
        }
    }
    

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);
        vector<int> isVisited(V, 0);
        
        for(int i=0;i<V;i++) {
            inDegreeFind(adj, i, inDegree, isVisited);
        }
        
        topologicalSortBfs(V, adj, inDegree); 

        for(int i:inDegree) {
            if(i) return true;
        }
        
        return false;
    }
};
