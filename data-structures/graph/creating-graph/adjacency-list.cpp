#include<iostream>
#include<list>

using namespace std;

/**
 * LOGIC: We will use list(doubly linked list)-> read about it in revision.txt of graph
 * - We need some Data Structure which is like...
 * - indices which containing list of items along
 * 
 */ 

class Graph {
    
    // pointer to array of list of int (did as we require size dynamically)
    list<int> *graph;
    int vertices;

    public:
    Graph(int vertices) {
        this->vertices = vertices;

        // create array of list of int and assign it to ptr
        this->graph = new list<int>[vertices];
    }

    void addVertices(int node1, int node2, bool isBidirection) {
        this->graph[node1].push_back(node2);
        if(isBidirection)
            this->graph[node2].push_back(node1);

    }

    void printAll() {
        for(int i=0;i< this->vertices;i++) {
            cout<<"Node "<<i<<" -- > ";
            for(auto j: this->graph[i]) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph* myG = new Graph(5);
    myG->addVertices(0,1,true);
    myG->addVertices(2,4,true);
    myG->addVertices(2,1,true);
    myG->addVertices(1,4,true);
    myG->printAll();
}
