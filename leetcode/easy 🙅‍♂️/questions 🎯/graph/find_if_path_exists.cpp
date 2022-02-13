// https://leetcode.com/problems/find-if-path-exists-in-graph/

/**
 * LOGIC: No need to use a seperate class for Graph
 * - Directly create map<int, vector<int>> graph.... and start doing operations
 * - [p1,p2]... push all these edges in the graph 
 * 
 */ 
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        //create graph
        map<int, vector<int>> graph;
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // iterate and check till graph is null
        queue<int> q;
        q.push(source);
        vector<int> isVisited(n, 0);
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(int connectedEdges: graph[front]) {
                if(connectedEdges==destination) {
                    return true;
                }
                if(isVisited[connectedEdges]) continue;
                else {
                    q.push(connectedEdges);
                    isVisited[connectedEdges]=1;
                }
            }
        }
        return false; 
    }
};
