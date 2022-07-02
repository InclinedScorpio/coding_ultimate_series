// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#


/**
 * QUESTION: Bipartite means if the graph can be colored with 2 colors such that no 2 are adjacent
 * - Just a heads up - we don't require to change color from 1 to 2 if one of them is not possible because that would be similar to before
 * 
 * - Also remember graph can be made of multiple componenets so run a for loop with visited array!
 * 
 * LOGIC: Color the first node with 1 color and push in queue (bfs)
 * - Now just keep coloring the adjacent nodes with alternative color
 * - And if visited node is seen just check if it has the same color with current(adjacent) node
 * - If yes then graph can't be bipartite
 * 
 * COMPLEXITY: O(N + E)
 * - Nodes + Edges
 */ 
class Solution {
public:
    bool helper(int V, int ind, vector<int>& visited, vector<bool>& colored, vector<int>adj[]){
	    queue<pair<int, bool>> store;
	    store.push({ind, true});
	    colored[ind] = true;
	    visited[ind] = 1;
	    
	    while(!store.empty()) {
	        pair<int, bool> front = store.front();
            visited[front.first]=1;
	        store.pop();
	        for(int i: adj[front.first]) {
	            if(visited[i] && colored[i]==front.second) return false;
	            if(!visited[i]) {
	                visited[i]=1;
	                colored[i] = !front.second;
	                store.push({i, !front.second});
	            }
	        }
	    }
	    return true;
	}


	bool isBipartite(int V, vector<int>adj[]){
        vector<int> visited(V, 0);
        vector<bool> colored(V);
	    for(int i=0;i<V;i++) {
	        if(visited[i]) continue;
	        if(!helper(V, i, visited, colored, adj)) {
	            return false;
	        }
	    }
	    return true;
	}
};