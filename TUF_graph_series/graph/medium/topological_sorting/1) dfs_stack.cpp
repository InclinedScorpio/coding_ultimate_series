// https://practice.geeksforgeeks.org/problems/topological-sort/1#

/**
 * UNDERSTANDING: Understanding what is topological sort is important
 * - Just FYI: It's not sorting!
 * 
 * TOPOLOGICAL SORTING: Means arrange all the node in such a way if we pick u and v (where index u<v)
 * - Then in graph u -> v (u comes before) or vice versa
 * 
 * NOTE: 
 * 1) For this to happen, graph must be Directed, as adirected will have direction both sides and we won't know which should be first
 * 2) Also, graph must not contain any cycle! Why? A -> B -> C -> A (now topological sort: A, B, C) <- wrong as A comes after C (so for cyclic topologic not possible)
 * 
 * - Hence Topological sorting can only be done in DAG (Directed Acyclic Graph only)
 * 
 * LOGIC: We just need to do DFS and use a stack
 * - Why stack? In stack at bottom will be the item which has no outgoing edges
 * - And as we go on top will have nodes which are having more outgoing edges
 * - Hence, at last we can just pop them out and print it
 * - So Topological sorting is basically ( DFS + STACK + VISITED_ARRAY)
 * 
 * - Make sure to push in stack only when reached at last
 * 
 * COMPLEXITY: O(N+E)
 */ 
class Solution {
	public:
	
	void helper(vector<int> adj[], int ind, vector<int>& isVisited, stack<int>& store) {
	    if(isVisited[ind]) return;
	    isVisited[ind]=1;
	    for(int i: adj[ind]) {
	        helper(adj, i, isVisited, store);
	    }
	    store.push(ind);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> store;
	    vector<int> isVisited(V, 0);
	    for(int i=0;i<V;i++) {
	        helper(adj, i, isVisited, store);
	    }
	    vector<int> result;
	    while(!store.empty()) {
	        result.push_back(store.top());
	        store.pop();
	    }
	    return result;
	}
};