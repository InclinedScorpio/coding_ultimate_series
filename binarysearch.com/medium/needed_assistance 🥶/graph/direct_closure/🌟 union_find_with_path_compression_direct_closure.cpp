// https://binarysearch.com/problems/Direct-Closure

/**
 * LOGIC: As we are required to find if vertices are connected to other vertices
 * - We can make use of union find to find if the connection exists
 * 
 * UNION FIND WITH PATH COMPRESSION
 * - Path compression called because in findParent method we are compressing the path
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
int findParent(int a, vector<int>& parent) {
    if(parent[a]== -1) return a;
    return parent[a] = findParent(parent[a], parent);
}

void unionNode(int a, int b, vector<int>& parent, vector<int>& rank) {
    int parentA = findParent(a, parent);
    int parentB = findParent(b, parent);
    if(parentA == parentB) return;
    if(rank[parentA] > rank[parentB]) {
        parent[parentB] = parentA;
    } else if(rank[parentB]>rank[parentA]) {
        parent[parentA] = parentB;
    } else {
        parent[parentA] = parentB;
        rank[parentB]++;
    }
}

vector<vector<int>> solve(vector<vector<int>>& graph) {
    vector<int> parent(graph.size(), -1);
    vector<int> rank(graph.size(), 0);

    for(int i=0;i<graph.size();i++) {
        for(int j: graph[i])
            unionNode(i, j, parent, rank);
    }
    vector<vector<int>> result(graph.size(), vector<int>(graph.size(), 0));
    for(int i=0;i<graph.size();i++) {
        for(int j=0;j<graph.size();j++) {
            if(findParent(i, parent)==findParent(j, parent)) {
                result[i][j] = 1;
                result[j][i] = 1;
            }
        }
    }
    return result;
}