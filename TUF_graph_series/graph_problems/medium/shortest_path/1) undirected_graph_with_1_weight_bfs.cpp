/**
 * PROBLEM: Given a source node, find smallest distance to all the other nodes
 * 
 * LOGIC: As we know bfs goes level by level, hence we can make use of it and increment size as we move forward
 * - We will push the node again in queue if the lentth is updated to any smaller value
 * - Or else if length is already small, we won't push it in queue
 * 
 * NOTE: Make sure to keep the length initially to INT_MAX so those can be updated
 * 
 * COMPLEXITY: O(N+E)
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

void helper(vector<int> adj[], int ind, int source, vector<int>& minDistances) {
    queue<int> q;
    q.push(ind);
    while(!q.empty()) {
        int front = q.front();
        cout<<front<<endl;
        q.pop();
        for(int i: adj[front]) {
            cout<<ind<<endl;
            if(minDistances[i]>(minDistances[front]+1)) {
                minDistances[i] = minDistances[front]+1;
                q.push(i);
            }
        }
    }
}

vector<int> findMinDistanceFromSource(vector<int> adj[], int V, int source) {
    vector<int> minDistances(V, INT_MAX);
    minDistances[source]=0;
    vector<int> isVisited(V, 0);
    helper(adj, source, source, minDistances);
    return  minDistances;
}

int main() {
    int V = 9;
    vector<int> adj[V];
    adj[0] = {1, 3};
    adj[1]={0, 2, 3};
    adj[2]={1, 6};
    adj[3]={0, 4};
    adj[4]={3, 5};
    adj[5]={4, 6};
    adj[6]={2, 5, 7, 8};
    adj[7]={6, 8};
    adj[8]={6, 7};

    int source=7;
    vector<int> minDistances = findMinDistanceFromSource(adj, V, source);
    for(int i=0;i<V;i++) {
        cout<<"Min distance from "<<source<<" to "<<i<<" is: "<<minDistances[i]<<endl;
    }
}
