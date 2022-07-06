// https://practice.geeksforgeeks.org/problems/topological-sort/1/

/**
 * “KAHN's ALGORITHM“
 * 
 * QUESTION: Important to understand what is topological sorting, checkout dfs_stack.cpp to understand it 
 * 
 * LOGIC: Using BFS, we need to pick those node first which has minimum incoming degrees
 * - Hence first we need to find all the indegrees
 * - Then pick those which have 0 indegrees (will be there as it's DAG)
 * - Now, just do BFS and keep inserting node whose indegree turn to 0...
 * - Hence we will get topological sort in the result
 * 
 * 
 * NOTE: During BFS we will keep reducing the indegree of the connected node so we can push the new zero degree node to the queue
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 

class Solution {
	public:
	
	void inDegree(vector<int> adj[], int ind, vector<int>& inDegrees, vector<int>& isVisited) {
	    if(isVisited[ind]) return;
	    queue<int> q;
	    q.push(ind);
	    
	    while(!q.empty()) {
	        int front = q.front();
	        q.pop();
	        if(isVisited[front]) continue;
            isVisited[front]=1;
	        for(int i: adj[front]) {
	            inDegrees[i]+=1;
	            q.push(i);
	        }
	    }
	}
	
	void bfsTopologicalSort(int V, vector<int> adj[], int ind, vector<int>& inDegrees, vector<int>& result) {
	    queue<int> q;
	    for(int i=0;i<V;i++) {
	        if(inDegrees[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()) {
            int front = q.front();
            result.push_back(front);
            q.pop();
            for(int i: adj[front]) {
                inDegrees[i]-=1;
                if(inDegrees[i]==0) {
                    q.push(i);
                }
            }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{ // using dfs
	    vector<int> isVisited(V, 0);
	    vector<int> inDegrees(V, 0);
	    
	    for(int i=0;i<V;i++) {
	        inDegree(adj, i, inDegrees, isVisited);
	    }
	    
	    vector<int> result;
	    
	    // bfsTopologicalSort
	    bfsTopologicalSort(V, adj, 0, inDegrees, result);
	    return result;
            
	}
};