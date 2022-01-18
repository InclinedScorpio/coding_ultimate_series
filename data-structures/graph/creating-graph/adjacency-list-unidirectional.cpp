#include<iostream>
#include<list>
#include<map>
#include<vector>

using namespace std;

/**
 * LOGIC: using a map to store node name (as index won't be feasible here)
 * - map is used to map city name to the Node* (address to that node)
 * 
 * 
 * NOTE: It's a unidirectional map with nodes containing details 
 * - hence we require a seperate class for node where we can store node related data
 * 
 */ 
class Node {
    public:
    string name;
    vector<string> wayTo;

    Node(string name) {
        this->name = name;
    }

    void addWayTo(string to) {
        this->wayTo.push_back(to);
    }
};

class Graph {

    public:
    map<string, Node*> store;

    void addNode(string from, string to) {
        if(store[from]){
            store[from]->addWayTo(to);
        }else {
            Node *node = new Node(from);
            node->addWayTo(to);
            store[from] = node;
        }
    }

    void showGraph() {
        map<string, Node*>::iterator itr;
        for(itr=store.begin(); itr!=store.end();itr++) {
            cout<<"Node: "<<itr->first<<" --> ";
            for(int i=0;i<itr->second->wayTo.size();i++) {
                cout<<itr->second->wayTo[i]<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {

    Graph *graph = new Graph();
    graph->addNode("Delhi", "London");
    graph->addNode("Delhi", "Paris");
    graph->addNode("Paris", "New York");
    graph->addNode("New York", "London");

    /**
     * Node: Delhi --> London, Paris, 
     * Node: New York --> London, 
     * Node: Paris --> New York,
     * 
     */ 
    graph->showGraph();
}
