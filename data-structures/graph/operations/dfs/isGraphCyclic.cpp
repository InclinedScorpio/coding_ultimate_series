#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
    list<int> *graph;
    int vertices;

    public:
    Graph(int vertices) {
        this->vertices = vertices;
        this->graph = new list<int>[vertices];
    }

    void addEdges(int from, int to, bool isBidirectional = false) {
        this->graph[from].push_back(to);
        if(isBidirectional) this->graph[to].push_back(from);
    }

    bool bfsCycleChecker(int node, int parentNode, bool *isVisited) {
        bool isCycle=false;
        isVisited[node]=1;
        for(int connectedNode: graph[node]) {
            if(connectedNode==parentNode) continue;
            if(!isVisited[connectedNode]) {
                isVisited[connectedNode] = 1;
                isCycle = bfsCycleChecker(connectedNode, node, isVisited);
            } else {
                return true;
            }
        }
        return isCycle;
    }

    /**
     * We can use any - DFS or BFS. Here we will use DFS
     * LOGIC: Point is to see if the adjacent node is already visited given it's not the parentNode from where it's attached and coming from
     * - Basically just do DFS and keeping checking if adjacent is non parent and already visited.
     * 
     */ 
    bool checkCycleExists(int startingNode){
        bool *isVisited = new bool[vertices]{0};
        return bfsCycleChecker(startingNode, -1, isVisited);
    }
};

int main() {
    Graph graph(6);
    graph.addEdges(1, 2);
    graph.addEdges(1, 0);
    graph.addEdges(0, 4);
    graph.addEdges(4, 5);
    graph.addEdges(0, 5);
    cout<<"Cycle Exists: "<<graph.checkCycleExists(1);
}
