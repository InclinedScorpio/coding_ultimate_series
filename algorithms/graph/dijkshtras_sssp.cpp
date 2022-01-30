#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<limits.h>
#include<string.h>

using namespace std;

class Graph {
    list<pair<int, int>>* graph;
    int vertices;
    vector<int> minDistance;
    public:
    void verify()  {
        for(int i=0;i<vertices;i++) {
            cout<<minDistance[i]<<" ";
        }
    }
    Graph(int vertices) {
        this->graph = new list<pair<int, int> >[vertices];
        this->vertices = vertices;
    }

    void addEdges(int from, int to, int weight, bool isUnidirectional=true) {
        graph[from].push_back({to, weight});
        if(isUnidirectional) graph[to].push_back({from, weight});
    }

    void findMinDistance(int from, vector<int> &minDistance, vector<int>& isVisited) {
        if(isVisited[from]) {
            return;
        }
        set<pair<int,int>> store;
        store.insert({0, from});

        while(!store.empty()) {
            auto nodePair = store.begin();
            isVisited[nodePair->second] = 1;
            store.erase(nodePair);
            int distTillNow = nodePair->first;
            int currentNode = nodePair->second;
            for(pair<int,int> connectedNode: graph[currentNode]) {
                if(isVisited[connectedNode.first]) {
                    continue;
                }
                if(minDistance[currentNode] + connectedNode.second < minDistance[connectedNode.first]) {
                    minDistance[connectedNode.first] = minDistance[currentNode] + connectedNode.second;

                    if(store.find({minDistance[connectedNode.first], connectedNode.first})!=store.end()) {
                        store.erase({minDistance[connectedNode.first], connectedNode.first});
                    }
                    store.insert({minDistance[connectedNode.first], connectedNode.first});
                }
            }
        } 
        this->minDistance = minDistance;
        int isPrinted[vertices];
        memset(isPrinted, 0, sizeof(isPrinted));
        cout<<" ************ Dijshtras's Print *************"<<endl;
        printAllEdgesWithSmallestDistance(from, isPrinted);
    }

    void printAllEdgesWithSmallestDistance(int from, int *isPrinted) {
        isPrinted[from]=1;
        cout<<from<<" ("<<this->minDistance[from]<<")"<<endl;
        for(pair<int, int> connectedNodes: graph[from]) {
            if(isPrinted[connectedNodes.first]) {
                continue;
            }
            printAllEdgesWithSmallestDistance(connectedNodes.first, isPrinted);
        }
    }

    /**
     * LOGIC: We will start from one node (Single Source Shorted Path - SSSP)
     * - Use set to keep the node and it's shortest distance - set<pair<int,int> - it will be sorted key(distance) wise
     * - Now in set we will always have the node with shortest distance known
     * - Now jump to that node and find distance to all connected nodes
     * - If connected nodes distance is less than their current minimum distance, update it and push in set
     * LOGIC: We pushed that updated node in set because from that updated node we again need to calculate shortest distance to connected nodes
     * - Now, repeat- keep pulling out nodes from set and calculate minimum distance
     * - At last when set becomes empty, that means all nodes are updated with their minimum distance
     * 
     * DOWNSIDE: This won't work with edges as -ve, as it would lead to INFINITY as nodes will keep updating with min distance
     * 
     */ 
    void dijkshtrasAlgo(int from) {
        vector<int> minDistance(vertices, INT_MAX);
        minDistance[from] = 0;
        vector<int> isVisited(vertices, 0);
        findMinDistance(from, minDistance, isVisited);
    }
};

int main() {
    Graph graph(5);
    graph.addEdges(0, 1, 1);
    graph.addEdges(1, 2, 1);
    graph.addEdges(0, 3, 7);
    graph.addEdges(0, 2, 4);
    graph.addEdges(3, 4, 3);
    graph.addEdges(3, 2, 2);
    graph.dijkshtrasAlgo(0);
}
