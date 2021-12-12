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
    // existed links will be updated again & at last NULL comes so base case will return the new node
    if(data>node->data) {
        node->right =  insertNode(node->right, data);
    }else {
        node->left = insertNode(node->left, data);
    }
    return node;
}

int main() {
    Node* root = NULL;
    int arr[] =  {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int x: arr) {
        root = insertNode(root, x);
    }
}
