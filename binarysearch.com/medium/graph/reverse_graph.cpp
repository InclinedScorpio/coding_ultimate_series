// https://binarysearch.com/problems/Reverse-Graph

/**
 * LOGIC: Basic understanding of adjacency list, that's all
 * 
 * 
 * 
 */
vector<vector<int>> solve(vector<vector<int>>& graph) {
    vector<vector<int>> store(graph.size());
    for(int i=0;i<graph.size();i++) {
        for(int j=0;j<graph[i].size();j++) {
            store[graph[i][j]].push_back(i);
        }
        cout<<endl;
    }
    return store;
}