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

Node* insertNode(Node* node, int data) {
    if(node==NULL) {
        return new Node(data);
    }
    if(data>node->data) {
        node->right =  insertNode(node->right, data);
    }else {
        node->left = insertNode(node->left, data);
    }
    return node;
}

/**
 * NOTE: Inorder traversal returns sorted* list from BST
 * 
 */ 
void inOrderTraversal(Node* node) {
    if(node==NULL) {
        return;
    }
    inOrderTraversal(node->left);
    cout<<node->data<<" ";
    inOrderTraversal(node->right);
}


int main() {
    Node* root = NULL;
    int arr[] =  {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int x: arr) {
        root = insertNode(root, x);
    }

    inOrderTraversal(root); // will give sorted list
}
