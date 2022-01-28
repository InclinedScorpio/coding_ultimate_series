#include<iostream>
#include<list>

using namespace std;

class Graph {
    list<int> *graph;
    int vertices;

    public:
    Graph(int vertices) {
        this->graph = new list<int>[vertices];
        this->vertices = vertices;
    }

    void addEdges(int from, int to, bool isBidirectional=false) {
        this->graph[from].push_back(to);
        if(isBidirectional) {
            this->graph[to].push_back(from);
        }
    }

    // pair returned is the backedge... 
    pair<int,int>* returnBackEdgeIfPresent(int node, int comingFrom, bool *isVisited) {
        if(isVisited[node]==1) {
            return new pair<int,int>{comingFrom, node};
        }
        isVisited[node] = 1;
        pair<int,int>* store= new pair<int,int>{-1, -1 };
        for(int attachedNode: graph[node]) {
            store = returnBackEdgeIfPresent(attachedNode, node, isVisited);
            if(store->first!=-1) break;
        }
        return store;
    }

    /**
     * QUESTION: Edge which results in the loop is called BackEdge and here we need to find that
     * LOGIC: Similar to isGraphCyclic-bidirectional, just that here we don't have edge going both sides ^^
     * 
     * Here, I have followed DFS to calculate.
     * COMPLEXITY: O(Edges + Vertices)
     */ 
    pair<int,int>* getBackEdgeIfPresent(int node) {
        bool *isVisited = new bool[vertices]{0};
        return returnBackEdgeIfPresent(node, -1, isVisited);
    }
};

int main() {
    Graph *graph = new Graph(6);
    graph->addEdges(2,3);
    graph->addEdges(1,2);
    graph->addEdges(1,0);
    graph->addEdges(0,4);
    graph->addEdges(5,0);
    graph->addEdges(4,5);
    pair<int,int>* backEdge = graph->getBackEdgeIfPresent(1);
    cout<<backEdge->first<<" "<< backEdge->second;
}
