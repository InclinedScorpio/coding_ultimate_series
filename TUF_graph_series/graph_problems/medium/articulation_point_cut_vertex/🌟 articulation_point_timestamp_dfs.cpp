/**
 * QUESTION: Find the articulation points in the graph
 * Articulation point is the single point of failure
 * Meaning if that nodes get removed, graph will be divided to two or more component
 * 
 * NOTE: Do Bridges Graph problem before this
 * - It's similar to that, we just need to maintain time and lowest time node seen
 * 
 * LOGIC: Maintain visited array first to check which nodes are visited
 * - We will do a DFS Traversal here
 * - Keep updating the time at which the node was seen
 * - Also if node encounters another node which has lower time of seen
 * - It will acquire it and return back to the node from where it came
 * - So that previous node can know that even if they are removed, the other graph can still reach the previous nodes hence it's not an articulation point
 * - The point where the next node returns lowerstTime same or more -> that means that node is articulation pt, as next node can reach the prvious part of the graph!
 * 
 * COMPLEXITY: O(V+E)
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int findArticulationPoints(vector<int> adj[], int ind, int val, int comingFrom, vector<int>& visited, vector<int>& timestamp, vector<int>& lowestTime, vector<int>& result_articulationPoints) {
    if(visited[ind]) return lowestTime[ind]; //already visited, return lowestTime
    
    visited[ind]=1;
    timestamp[ind]=val;
    lowestTime[ind]=val;
    
    bool isArticulationPoint = false;
    int minTimeStampValue = val;

    int childCounter=0;
    for(int i: adj[ind]) {
        if(i==comingFrom) continue;

        // check if root node(parent == -1 is also and articulation pt)
        // it will be articulation pt if there are >1 childeren which are disconnected!
        childCounter++;
        if(comingFrom==-1 && childCounter>1 && !visited[i]) { // for parent node articulation check
            isArticulationPoint = true;
            result_articulationPoints.push_back(ind);
        }

        int lowestTimeSeen = findArticulationPoints(adj, i, val+1, ind, visited, timestamp, lowestTime, result_articulationPoints);
        if(!isArticulationPoint && lowestTimeSeen>=timestamp[ind] && comingFrom!=-1) {
            isArticulationPoint = true;
            result_articulationPoints.push_back(ind);
        }
    
        minTimeStampValue = min(minTimeStampValue, lowestTimeSeen);
    }
    lowestTime[ind] = minTimeStampValue;
    return minTimeStampValue;
}

int main() {
    int nodes, edges;
    cout<<"Enter nodes: ";
    cin>>nodes;
    cout<<endl<<"Enter edges: ";
    cin>>edges;
    vector<int> adj[nodes];

    for(int i=0;i<edges;i++) {
        cout<<endl<<"Mention edge ("<<i+1<<"): ";
        int from, to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<int> result_articulationPoints;
    vector<int> visited(nodes, 0);
    vector<int> timestamp(nodes, 0);
    vector<int> lowestTime(nodes, 0);

    findArticulationPoints(adj, 0, 0, -1, visited, timestamp, lowestTime, result_articulationPoints);

    cout<<"Result: ";
	for(int i: result_articulationPoints) {
        cout<<i<<" ";
    }
    
	return 0;
}