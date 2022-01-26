#include<iostream>
#include<list>
#include<queue>
using namespace std;

/**
 * NOTE: Think BFS as level traversal and then proceed.
 *
 */ 
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

    /**
     * LOGIC: Already covered in data-structures > graph > traversing-graph > traversal
     * 
     */ 
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

    /**
     * LOGIC: Already covered in data-structures > graph > traversing-graph > distance > min distance to each node
     * 
     */ 
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

    /**
     * LOGIC: Already covered in data-structures > graph > traversing-graph > distance > min distance to each node
     * 
     * HINT: Just run BFS and store the parents so you can backtrack :)
     */ 
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

    /**
     * UTILITY method for findMinimumPathForNode
     * PURPOSE: Backtracks and tells the path
     * 
     */ 
    void trackPath(int startingNode, int endingNode, vector<int>& parentNode, vector<int>& minDistance) {
        cout<<"-----Path Followed-----"<<endl;
        while(endingNode!=startingNode) {
            cout<<endingNode<<" <--("<<minDistance[endingNode]<<")-- ";
            endingNode = parentNode[endingNode];
        }
        cout<<startingNode;
    }
};

int main() {
    int sizeOfSnakesAndLadder=36; //enter total number of game blocks in snakes and ladders
    Graph *graph = new Graph(sizeOfSnakesAndLadder+1); // 0th index is not considered here in game so take 1 more index

    vector<pair<int,int>> ladders = {{1,22}, {14, 36}}; // mention ladders
    vector<pair<int,int>> snakes = {{22, 14}}; // mention snakes

    // create graph for ladders
    for(pair<int,int>ladderPair: ladders) {
        graph->addEdges(ladderPair.first, ladderPair.second);    
    }

    //create graph for snakes
    for(pair<int,int>snakePair: snakes) {
        graph->addEdges(snakePair.first, snakePair.second);
    }

    //IMPORTANT: Create graph for complete snakes and ladders
    //NOTE: We are going to run BFS so join every possible blocks in the game!
    for(int node=1;node<sizeOfSnakesAndLadder;node++) {
        for(int face=1;face<=6;face++){
            int newNode = node+face;
            if(newNode<=sizeOfSnakesAndLadder){
                graph->addEdges(node, newNode);
            }
        }
    }
    
    // OPERATIONS
    graph->bfs(1);

    cout<<endl<<"***************"<<endl;

    graph->findShortestDistance(1);

    cout<<endl<<"***************"<<endl;

    //finds path btw 2 nodes
    graph->findMinimumPathForNode(1, 36);
}
