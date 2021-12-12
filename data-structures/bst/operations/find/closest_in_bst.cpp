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
/**
 * COMPLEXITY: O(Height) - in case of recursion we will traverse till the last
 * O(1) - in case of iterative approach
 * LOGIC: Pick the required branch on each step
 * 
 */ 
int closestInBST(Node* node, int key){
    if(node==NULL) {
        return closest;
    }
    int currClosest = abs(node->data - key);
    if(closest > currClosest) {
        closest = node->data;
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
    root->right->right = new Node(12);
    root->right->right->right = new Node(23);
    root->right->right->left = new Node(13);
    cout<<closestInBST(root, 16);
}
