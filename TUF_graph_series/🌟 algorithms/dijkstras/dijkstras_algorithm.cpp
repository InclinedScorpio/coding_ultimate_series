/**
 * PROBLEM: Dijstras algorithm works good when weighted graph is given
 * NOTE: NO NEGATIVE WEIGHT OR ELSE IT WON'T WORK!
 * 
 * LOGIC: In BFS we used to push the all nodes in next level to the queue
 * - But in that case it would push even the node with largest edge weight to the queue
 * 
 * - Whereas in Dikstras, it's similar to BFS, but here we will use priority queue
 * - WHY? so that we can initially discover those nodes which has shortest length from source 
 * - From those nodes we can update the shortest length to other nodes (RELAXATION PROCESS)
 * - Hence, as we keep reaching the new nodes(picking node from priority queue means the length of that node is set to smallest now)
 * 
 * COMPLEXITY: O(E + VlogV)
 * 
 */ 


#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

vector<int> helper(vector<pair<int, int>> adj[], int V, int source, vector<int> minDistance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});

    while(!minHeap.empty()) {
        pair<int, int> topItem = minHeap.top(); // o(n)

        minHeap.pop();

        int distanceTill = topItem.first;

        int node = topItem.second;
        for(pair<int, int> i: adj[node]) {
            if(i.second+distanceTill < minDistance[i.first]) {
                minDistance[i.first] = i.second+distanceTill;
                minHeap.push({minDistance[i.first], i.first});
            }
        }
    }
    return minDistance;
}

vector<int> minDistanceDijkstrasAlgo(vector<pair<int, int>> adj[], int V, int source) {
    vector<int> minDistance(V+1, INT_MAX);
    minDistance[source]=0;
    return helper(adj, V, source, minDistance);
}

int main() {
    int V = 6;
    vector<pair<int, int>> adj[V];
    adj[1] = {{2, 2}, {4, 1}};
    adj[2] = {{1, 2}, {5, 5}, {3, 4}};
    adj[3] = {{2, 4}, {4, 3}, {5, 1}};
    adj[4] = {{1, 1}, {3, 3}};
    adj[5] = {{2, 5}, {3, 1}};

    int source=1;
    vector<int> minDistances = minDistanceDijkstrasAlgo(adj, V, source);
    for(int i=0;i<V;i++) {
        cout<<"Min distance from "<<source<<" to "<<i<<" is: "<<minDistances[i]<<endl;
    }
}
