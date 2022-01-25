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

    void showEdges() {
        for(int i=0;i<this->vertices;i++) {
            cout<<"Node: "<<i<<" => ";
            for(int i: this->graph[i]) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(int startingNode) {
        queue<int> store;
        store.push(startingNode);
        vector<int> isVisited(this->vertices, 0);
        cout<<startingNode<<" ";
        isVisited[startingNode]=1;
        while(!store.empty()){
            int currNode = store.front();
            store.pop();
            for(int attachedNodes: this->graph[currNode]) {
                if(!isVisited[attachedNodes]) {
                    cout<<attachedNodes<<" ";
                    store.push(attachedNodes);
                    isVisited[attachedNodes]=1;
                }
            }
        }
    }

    void findShortestDistance(int startingNode) {
        queue<int> store;
        store.push(startingNode);
        vector<int> isVisited(this->vertices, 0);
        vector<int> minDistance(this->vertices, 0);
        cout<<startingNode<<"(0) ";
        isVisited[startingNode]=1;
        
        while(!store.empty()){
            int currNode = store.front();
            store.pop();
            for(int attachedNodes: this->graph[currNode]) {
                if(!isVisited[attachedNodes]) {
                    cout<<attachedNodes<<"";
                    store.push(attachedNodes);
                    isVisited[attachedNodes]=1;
                    minDistance[attachedNodes] = minDistance[currNode] + 1;
                    cout<<"("<<minDistance[attachedNodes]<<") ";
                }
            }
        }
    }

    void findMinimumPathForNode(int startingNode, int endingNode){
        queue<int> store;
        store.push(startingNode);
        vector<int> isVisited(this->vertices, 0);
        vector<int> parentNode(this->vertices, -1);
        vector<int> minDistance(this->vertices, 0);
        isVisited[startingNode]=1;
        parentNode[0]=-2;
        while(!store.empty()){
            int currNode = store.front();
            store.pop();
            for(int attachedNodes: this->graph[currNode]) {
                if(!isVisited[attachedNodes]) {
                    store.push(attachedNodes);
                    isVisited[attachedNodes]=1;
                    parentNode[attachedNodes] = currNode;
                    minDistance[attachedNodes] = minDistance[currNode] + 1;
                }
            }
        }
        trackPath(startingNode, endingNode, parentNode, minDistance);
    }

    void trackPath(int startingNode, int endingNode, vector<int>& parentNode, vector<int>& minDistance) {
        cout<<"****** Path Followed ********"<<endl;
        while(endingNode!=startingNode) {
            cout<<endingNode<<" <--("<<minDistance[endingNode]<<")-- ";
            endingNode = parentNode[endingNode];
        }
        cout<<startingNode;
    }
};

int main() {
    int sizeOfSnakesAndLadder=36; //enter total number of game blocks in snakes and ladders
    Graph *graph = new Graph(sizeOfSnakesAndLadder+1);

    vector<pair<int,int>> ladders = {{1,22}, {14, 36}};
    vector<pair<int,int>> snakes = {{22, 14}};
    for(pair<int,int>ladderPair: ladders) {
        graph->addEdges(ladderPair.first, ladderPair.second);    
    }
    for(pair<int,int>snakePair: snakes) {
        graph->addEdges(snakePair.first, snakePair.second);
    }
    for(int node=1;node<sizeOfSnakesAndLadder;node++) {
        for(int face=1;face<=6;face++){
            int newNode = node+face;
            if(newNode<=sizeOfSnakesAndLadder){
                graph->addEdges(node, newNode);
            }
        }
    }
    graph->findMinimumPathForNode(1, 36);
}
