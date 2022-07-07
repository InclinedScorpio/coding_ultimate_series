/**
 * QUESTION: Similar to 1) undirected_graph_with_1_wight_bfs, with minor change
 * - Here adjacency list will not have int, rather pair<int, int>
 * - Why? As the edges are wighted, hence from for edge 1 connected to 0 with edge weight as 12 we will show as [0] = {{1, 12}}
 * 
 * - Hence, while checking the distance and pushing in queue we will check if it's yielding min distance
 * - If yes then update and insert it in queue (so that other connected nodes to it can also be updated)
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

void helper(vector<pair<int, int>> adj[], int ind, vector<int>& minDistances) {
    queue<int> q;
    q.push(ind);
    while(!q.empty()) {
        int front = q.front();
        cout<<front<<endl;
        q.pop();
        for(pair<int, int> i: adj[front]) {
            cout<<ind<<endl;
            if(minDistances[i.first]>(minDistances[front]+i.second)) {
                minDistances[i.first] = minDistances[front]+i.second;
                q.push(i.first);
            }
        }
    }
}

vector<int> findMinDistanceFromSource(vector<pair<int, int>> adj[], int V, int source) {
    vector<int> minDistances(V, INT_MAX);
    minDistances[source]=0;
    vector<int> isVisited(V, 0);
    helper(adj, source, minDistances);
    return  minDistances;
}

int main() {
    int V = 6;
    vector<pair<int, int>> adj[V];
    adj[0] = {{1, 2}, {4, 1}};
    adj[1] = {{2, 3}};
    adj[2] = {{3, 6}};
    adj[4] = {{2, 2}, {5, 4}};
    adj[5] = {{3, 1}};

    int source=0;
    vector<int> minDistances = findMinDistanceFromSource(adj, V, source);
    for(int i=0;i<V;i++) {
        cout<<"Min distance from "<<source<<" to "<<i<<" is: "<<minDistances[i]<<endl;
    }
}
