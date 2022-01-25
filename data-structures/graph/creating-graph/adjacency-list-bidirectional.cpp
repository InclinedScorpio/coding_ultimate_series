#include<iostream>
#include<list>

using namespace std;

/**
 *  Method used: Adjacency List!  
 *  list<int> *graph -> 0[ 1,2 ], 1[ 3,4 ], 2[5,6] ....
 *  graph holds array of list<int>, it can be list of Elephants also, depends on usecase! 
 * 
 *  LOGIC: We will use list(doubly linked list)-> read about it in revision.txt of graph
 * - We need some Data Structure which is like...
 * - ...indices which containing list of items along
 * 
 */ 
class Graph {
    public:

    // pointer to array of list of int (did as we require size dynamically)
    list<int> *graph; // *graph is basically an array which holds list<int> | array can be instantiated in constructor
    int noOfNodes; // storing nodes is important as this->graph is just a ptr and not an array

    Graph(int noOfNodes) {
        this->noOfNodes = noOfNodes;

        // create array of list of int and assign it to ptr
        graph = new list<int>[noOfNodes];
    }

    void addEdge(int node1, int node2, bool bidirectional=true) {
        graph[node1].push_back(node2);
        if(bidirectional) {
            graph[node2].push_back(node1);
        }
    }

    void printGraph() {
        int index = 0;
        for(auto i=0;i<noOfNodes;i++) {
            cout<<"Node "<<index++<<"=>";
            for(int connectedNodes: graph[i]) {
                cout<<connectedNodes<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph *graph = new Graph(6);

    graph->addEdge(0,1);
    graph->addEdge(0,4);
    graph->addEdge(4,3);
    graph->addEdge(4,5);
    graph->addEdge(1,2);
    graph->addEdge(2,3);
    graph->addEdge(5,3);

    /**
     * Output for graph->printGraph()
     * Node 0=>1 4 
     * Node 1=>0 2 
     * Node 2=>1 3 
     * Node 3=>4 2 5 
     * Node 4=>0 3 5 
     * Node 5=>4 3 
     * 
     */ 
    graph->printGraph();
}
