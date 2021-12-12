#include <iostream>
#include <map>
#include <queue>

using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data, Node* left=NULL, Node* right=NULL) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

int closest = INT_MAX;
int nearestValue;
/**
 * TIME-COMPLEXITY: O(N)
 * SPACE-COMPLEXITY: O(Height) - recursion | O(1) - iterative
 * LOGIC: Pick the required branch on each step
 * 
 */ 
int closestInBST(Node* node, int key){
    if(node==NULL) {
        return nearestValue;
    }
    int currClosest = abs(node->data - key);
    if(currClosest == 0) {
        return node->data;
    }

    if(closest > currClosest) {
        nearestValue = node->data;
        closest = currClosest;
    }
    if (node->data > key) {
        return closestInBST(node->left, key);
    } else {
        return closestInBST(node->right, key);
    }
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(15);
    root->right->right->right = new Node(25);
    root->right->right->left = new Node(13);
    cout<<closestInBST(root, 16);
}
