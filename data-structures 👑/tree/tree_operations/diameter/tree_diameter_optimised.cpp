#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data, Node* left=NULL, Node* right=NULL) {
            this->data = data;
        }
};

int ind = -1;
Node* createTree(int arr[]) {
    ind++;
    if(arr[ind]==-1) {
        return NULL;
    }
    Node* node = new Node(arr[ind]);
    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}

class MaxDetails {
    public:
        int depth;
        int maxDia;
        MaxDetails(int depth, int maxDia) {
            this->depth = depth;
            this->maxDia = maxDia;
        }
};


/**
 * COMPLEXITY: O(N)- only all nodes will be visited (as we are not finding depth on each node)
 * LOGIC: To Optimize, rather than finding depth on both sides on each node O(N^2)
 * Iterate back from the leaf to root node along calculating 2 things:
 * 1. Depth till current Node
 * 2. Maximum Diameter till current Node
 * - for this make use of a Class (MaxDetails) to store these 2 details
 * 
 */ 
MaxDetails* maxDiameter(Node* node) {

    // base Condition
    if(node==NULL) {
        return new MaxDetails(0, 0);
    }

    // will iterate till last
    MaxDetails* leftSubtree = maxDiameter(node->left);
    MaxDetails* rightSubtree = maxDiameter(node->right);

    // calculations for calucalting current depth and height
    int currMaxDia = leftSubtree->depth+ rightSubtree->depth;

    if( currMaxDia < leftSubtree->maxDia ) {
        currMaxDia = leftSubtree->maxDia;
    }else if (currMaxDia < rightSubtree->maxDia) {
        currMaxDia = rightSubtree->maxDia;
    }

    /**
     *  USE "+1" as returning node data must have the incremented depth
     *  "This logic depends upon us"
     */ 
    return new MaxDetails(max(leftSubtree->depth, rightSubtree->depth)+1, currMaxDia);
}

int main() {
/** TREE TAKEN - max Dia goes through: "2" and not the root Node
 * 
 *                                1
 *                          2           3
 *                      4       5      6  7
 *                    8   9   24 34
 *                      10   25   35
 *                    11    36
 */ 
    int treeData[] = {1, 2, 4, 8, -1, -1, 9, 10, 11, -1,-1, -1, -1, 5, 24, 25, 36, -1, -1, -1, -1, 34, 35, -1, -1, -1, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    Node* root = createTree(treeData);
    MaxDetails* node = maxDiameter(root);
    cout<<node->maxDia;
}
