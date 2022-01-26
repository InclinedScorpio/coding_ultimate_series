#include<iostream>
#include<list>

using namespace std;

class Graph {

    list<int> *graph;
    int vertices;

    public:
    Graph(int vertices) {
        this->vertices = vertices;
        this->graph = new list<int>[vertices];
    }
    
    void addEdges(int from, int to , bool isBidirectional) {
        this->graph[from].push_back(to);
        if(isBidirectional) this->graph[to].push_back(from);
    }

    void showEdges() {
        for(int node=0;node<vertices;node++) {
            cout<<"Node: "<<node<<" => ";
            for(int currNode: this->graph[node]) {
                cout<<currNode<<", ";
            }
            cout<<endl;
        }
    }

    void dfsTraversal(int node, bool *isVisited) {
        cout<<node<<" ";
        isVisited[node] = 1;
        for(int attachedNode: graph[node]) {
            if(!isVisited[attachedNode]) {
                dfsTraversal(attachedNode, isVisited);
            }
        }
    }

/**
 * LOGIC: DFS Depth First Search is similar to how we recursively traverse a tree
 * - It's important to keep a 'isVisited' record so that already visited node are not visited again (as loops are possible in graph)
 * - The operations just requires us to call all the adjacent nodes present with a node, which has to be recursive so all nodes are covered.
 * 
 * COMPLEXITY: Same as BFS O(Node+Edges) - a sum of all nodes and edges gives us the complexity of BFS and DFS!
 * 
 */ 
    void dfs(int startingNode) {
        bool *isVisited = new bool[vertices];
        memset(isVisited, 0, vertices);
        dfsTraversal(startingNode, isVisited);
    }
};

int main() {
    Graph graph(7);
    graph.addEdges(1, 0, true);
    graph.addEdges(1, 2, true);
    graph.addEdges(0, 3, true);
    graph.addEdges(2, 4, true);
    graph.addEdges(3, 5, true);
    graph.addEdges(4, 5, true);
    graph.addEdges(5, 6, true);
    graph.dfs(1);
}
