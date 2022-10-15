// https://leetcode.com/problems/is-graph-bipartite/

/**
 * LOGIC: Just basic DFS with isVisited array marking the coloring
 * 
 */ 
class Solution {
public:
    
    // 1 - red, 2 - blue
    bool helper(vector<vector<int>>& graph, int node, vector<int>& isVisited, int color) {
        int visitedColor = isVisited[node];
        if(visitedColor!=0 && visitedColor==color) return true;
        if(visitedColor!=0 && visitedColor!=color) return false;
        isVisited[node] = color;
        int nextColor = color==1 ? 2 : 1;
        for(int adjNode: graph[node]) {
            if(!helper(graph, adjNode, isVisited, nextColor)) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++) {
            vector<int> isVisited(graph.size(), 0);
            if(!helper(graph, i, isVisited, 1)) return false;
        }
        return true;
    }
};