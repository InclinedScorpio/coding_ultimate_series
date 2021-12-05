#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data, Node* left = NULL, Node* right=NULL) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

int ind=-1;
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

class NodeDetails {
    public:
        bool isBalanced;
        int height;
        NodeDetails(bool isBalanced=true, int height=0) {
            this->isBalanced = isBalanced;
            this->height = height;
        }
};

/**
 * COMPLEXITY: O(N)- all nodes visited only once (Post order)
 * 
 * BALANCE: means left & right height difference must not be > 1
 * 
 * LOGIC: post order traversal 
 * 1. Return MAX_HEIGHT (left, right) of curr node (keep doing + 1)
 * 2. Also, keep checking if |left-right| > 1 (means unbalanced)
 * 
 * If unbalanced found... means tree is unbalanced... keep returning unbalanced
 * 
 * ALTERNATIVE: Rather than class Pair<int, bool> pair could also be used:
 * pair.first - implies int
 * pair.second - implies bool
 */ 
NodeDetails* isTreeBalanced(Node* node) {
    // base condition
    if(node==NULL) {
        return new NodeDetails();
    }

    // Post Order Traversal
    NodeDetails* leftSubTree = isTreeBalanced(node->left);
    NodeDetails* rightSubTree = isTreeBalanced(node->right);

    // Node (operation)
    int balanceDiff = abs(leftSubTree->height - rightSubTree->height);
    NodeDetails* currNode = new NodeDetails();
    if(balanceDiff>1 || !leftSubTree->isBalanced || !rightSubTree->isBalanced) {
        currNode->isBalanced = false;
    }
    currNode->height = max(leftSubTree->height, rightSubTree->height) + 1;
    return currNode;
}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, 8, -1, -1, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    string ans = isTreeBalanced(root)->isBalanced? "Tree is Balanced":"Tree is not Balanced";
    cout<<ans;
}
