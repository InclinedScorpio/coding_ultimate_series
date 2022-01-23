#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph {
    list<int> *graph;
    int noOfNodes;
    public:
        Graph(int vertices) {
            graph = new list<int>[vertices];
            noOfNodes = vertices;
        }

        void addEdges(int from, int to, bool unidirectional) {
            graph[from].push_back(to);
            if(unidirectional) graph[to].push_back(from);
        }
        
        /**
         * 
         * LOGIC: Is similar to tree BFS
         * - Use a queue to keep the neighbour
         * - Pick front and insert it's neighbour in the queue
         * - Keep doing this
         * - NOTE: make sure to keep a record of visited node so you don't insert...
         * ... same node multiple times inside the queue (As cycles are possible)
         * 
         */ 
        void bfsTraversal(int startFrom) {
            queue<int> store;
            store.push(startFrom);
            int *nodesVisited = new int[noOfNodes]{0};
            while(!store.empty()) {
                int storeFront = store.front();
                store.pop();
                nodesVisited[storeFront] = 1;
                cout<<storeFront<<" ";
                for (int node: graph[storeFront]) {
                    if(!nodesVisited[node]) {
                        store.push(node);
                        nodesVisited[node] = 1;
                    }
                }
            }
        }
};

int main() {
    Graph *graph = new Graph(7);
    graph->addEdges(1,2, true);
    graph->addEdges(1,0, true);
    graph->addEdges(2,3, true);
    graph->addEdges(0,4, true);
    graph->addEdges(3,5, true);
    graph->addEdges(4,5, true);
    graph->addEdges(5,6, true);
    graph->bfsTraversal(1);
}
