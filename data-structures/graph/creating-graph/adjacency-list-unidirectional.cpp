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

    Graph(vector<string>& counteries) {
        for(string country: counteries) {
            store[country] = new Node(country);
        }
    }

    void addNode(string from, string to) {
        store[from]->addWayTo(to);
    }

    void showGraph() {
        for(auto nodes: this->store) {
            cout<<"Node: "<<nodes.first<<" --> ";
            for(string wayTo: nodes.second->wayTo) {
                cout<<wayTo<<", ";
            }
            cout<<endl;
        }

        // // MY INITIAL APPROACH (BETTER IS TO USE FOR EACH - CLEAN)
        // map<string, Node*>::iterator itr;
        // for(itr=store.begin(); itr!=store.end();itr++) {
        //     cout<<"Node: "<<itr->first<<" --> ";
        //     for(int i=0;i<itr->second->wayTo.size();i++) {
        //         cout<<itr->second->wayTo[i]<<", ";
        //     }
        //     cout<<endl;
        // }
    }
};

int main() {

    vector<string> countries = {"Delhi", "London", "Paris", "New York"};
    Graph *graph = new Graph(countries);
    
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
