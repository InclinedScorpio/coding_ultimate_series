/**
 * QUESTION: To check if 2 nodes exists in same component or different component
 * 
 * LOGIC: We make use of parents and ranks for nodes.
 * - Parent tell which is the parent of the node
 * - We try to keep the height minimum (it's a tree basically)
 * - While entering 2 nodes, we do union to show they are related
 * - While doing union - ALWAYS PICK THE PARENT OF THOSE NODE TO UNION
 * - Also the node which has less rank gets attached to larger rank (so rank doesn't increase)
 * - Rank increases only when same rank parent are union (!important)
 * 
 * ## Compression
 * - While doing find, if we see there are more steps to reach parent from a node, we do compression
 * - Compression will just make sure that all child nodes directly point to parent rather than forming chain
 * 
 */ 

#include<iostream>

using namespace std;

int parent[100000];
int nodeRank[100000];

void makeSet(int n) {
    for(int i=0;i<n;i++) {
        parent[i] = i;
        nodeRank[i] = 0;
    }
}

int findParent(int node) {
    if(parent[node]==node) {
        return node;
    }
    return parent[node]=findParent(parent[node]); //compression
}

void nodeUnion(int a, int b) {
    int parentOfA = findParent(a);
    int parentOfB = findParent(b);
    if(parentOfA == parentOfB) return;
    // always join smaller rank parent to larger rank parent! so rank remains the same (rank is basically depth!)
    if(nodeRank[parentOfA]<nodeRank[parentOfB]) { // rank won't change if smaller rank is joined to larger rank
        parent[parentOfA] = parentOfB;
    } else if(nodeRank[parentOfA]>nodeRank[parentOfB]) { // rank won't change if smaller rank is joined to larger rank
        parent[parentOfB] = parentOfA;
    } else { //rank eq
        parent[parentOfA] = parentOfB; 
        nodeRank[parentOfB]++;  // increase rank, as both have same rank!
    }
}

/**

           1  --- 2 -- 3
           |
           4    

        6 -- 7   8 -- 9
                 |
                 5
 */ 


int main() {
    makeSet(10);
    int connections;
    cout<<"Enter total connections:";
    cin>>connections;
    cout<<endl;
    for(int i=0;i<connections;i++) {
        cout<<"Enter "<<i+1<<" connection from:";
        int from, to;
        cin>>from;
        cout<<"Enter "<<i+1<<" connection to:";
        cin>>to;
        nodeUnion(from, to);
        cout<<endl;
    }

    cout<<"Type 2 numbers to check if in same set: ";
    int first, second;
    cin>>first;
    cin>>second;
    while(first>=0 && first<10 && second>=0 && second<10) {
        if(findParent(first)==findParent(second)) {
            cout<<"same set";
        } else {
            cout<<"Different set";
        }
        cout<<endl;
        cout<<"Type 2 numbers to check if in same set: ";
        cin>>first;
        cin>>second;
    }
}