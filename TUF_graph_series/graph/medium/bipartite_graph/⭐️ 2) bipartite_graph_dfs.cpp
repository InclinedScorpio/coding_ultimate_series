// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#

/**
 * LOGIC: Similar to BFS, it's just that in DFS we will use recursion
 * - Also don't get confused on tag line #1 that we again need to check ifVisited
 * - We don't need to do that as on tag line #2 we are already doing that for each iteration 
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 
class Solution {
public:
	
	bool helper(int V, int ind, bool currColor, vector<int>& isVisited, vector<int>& color, vector<int>adj[]){
	    if(isVisited[ind] && color[ind]!=currColor) return false; // #2
	    if(isVisited[ind]) return true;
	    // visited and color it
	    isVisited[ind] = 1;
	    color[ind] = currColor;
	    for(int i: adj[ind]) {
	        bool res = helper(V, i, !currColor, isVisited, color, adj); // #1
	        if(!res) return false;
	    }
	    return true;
	}
	
	bool isBipartite(int V, vector<int>adj[]){
        vector<int> isVisited(V, 0);
        vector<int> color(V, 0);
        for(int i=0;i<V;i++) {
            if(!isVisited[i] && !helper(V, i, true, isVisited, color, adj)) return false;
        }
        return true;
	}

};