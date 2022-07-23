https://binarysearch.com/problems/Direct-Closure

/**
 * LOGIC: It's a graph question, we can either do DFS/BFS in these questions
 * - Here we have done DFS. Make sure to use visited array
 * 
 * COMPLEXITY: O(N^2)
 * 
 */
void helper(vector<vector<int>>& graph, int ind, int indTo,  vector<vector<int>>& result, vector<vector<int>>& visited) {
    if(visited[ind][indTo]) return;
    result[ind][indTo] = 1;
    visited[ind][indTo] = 1;
    vector<int> connectedNodes = graph[indTo];
    for(int adj: connectedNodes) {
        helper(graph, ind, adj, result, visited);
    }
}

vector<vector<int>> solve(vector<vector<int>>& graph) {
    vector<vector<int>> result(graph.size(), vector<int>(graph.size()));
    vector<vector<int>> visited(graph.size(), vector<int>(graph.size()));
    for(int i=0;i<graph.size();i++) {
        helper(graph, i, i, result, visited);
    }
    return result;
}