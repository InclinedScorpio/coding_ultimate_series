// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#


/**
 * LOGIC: It's a graph problem with given in form of 2D-array
 * - We just need to color in such a way that no 2 adjacent have same color
 * 
 * - Hence we take an additional array to keep a check on what node has which color
 * 
 * - As there are multiple cases possible, hence we need to use recursion here
 * 
 * 
 * COMPLEXITY: O(M^N)
 * - _, _, _, _, _, _, _, _ ... (N spaces)
 * - M  M  M  M  M  M  M  M  ... (M possibilites in each)
 * - Hence total complexity O(M^N)
 * 
 */ 
bool helper(bool graph[101][101], int colored[], int m, int n, int node) {
    if(node>=n) return true;
    
    for(int color=1;color<=m;color++) {
        bool canPickColor=true;
        for(int edges=0;edges<n;edges++) {
            if(edges!=node && graph[node][edges] && colored[edges]==color) {
                    canPickColor = false;
                    break;
            }
        }
        if(canPickColor) {
            colored[node]=color;
            bool res = helper(graph, colored, m, n, node+1);
            if(res) return true;
        }
        colored[node]=0;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int colored[n] = {0};
    return helper(graph, colored, m, n, 0);
}
