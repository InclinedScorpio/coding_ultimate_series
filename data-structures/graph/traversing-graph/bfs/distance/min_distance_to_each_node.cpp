#include<iostream>
#include<list>
#include<queue>
#include<map>

using namespace std;

class Graph {
    list<int> *graph;
    int noOfNodes;
    map<int, int> distanceFromParent;
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
        * LOGIC: Basic
        * - Do BFS and keep storing the distances to the node
        * 
        * NOTE: Make sure to store the records of visited nodes
        * 
        */ 
        void findShortestDistanceToEachNode(int startingNode) {
            queue<int> store;
            store.push(startingNode);

            int *nodesVisited = new int[noOfNodes]{0};
            distanceFromParent[startingNode]=0;

            while(!store.empty()) {
                int frontNode = store.front();
                store.pop();
                for(int currNode: graph[frontNode]) {
                    if(distanceFromParent.find(currNode)==distanceFromParent.end())
                        distanceFromParent[currNode]=distanceFromParent[frontNode]+1;
                    
                    if(!nodesVisited[currNode])
                        store.push(currNode);
                    nodesVisited[currNode] = 1;
                }
            }
        }

        void printShortestDistanceToEachNode(int startingNode) {
            this->findShortestDistanceToEachNode(startingNode);
            map<int, int>:: iterator itr;
            cout<<"All nodes are distance from node: "<<startingNode<<endl;
            for(itr = distanceFromParent.begin(); itr!=distanceFromParent.end(); itr++) {
                cout<<"Node: "<<itr->first<<", distance: "<<itr->second<<endl;
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
    graph->printShortestDistanceToEachNode(1);
}
