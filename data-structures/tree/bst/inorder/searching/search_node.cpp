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
    if(data > node->data) {
        node->right =  insertNode(node->right, data);
    }else {
        node->left = insertNode(node->left, data);
    }
    return node;
}

/**
 * Min Complexity O(logN) & Max Complexity - O(N)
 * COMPLEXITY: O(Height_of_tree)
 * LOGIC: Keep rejecting branch where data won't be there
 * 
 */ 
bool searchNode(Node* node, int key) {
    if(node==NULL) {
        return false;
    }
    if(node->data == key) {
        return true;
    }
    if(key > node->data) {
        return searchNode(node->right, key);
    }else {
        return searchNode(node->left, key);
    }
}

int main() {
    Node* root = NULL;
    int arr[] =  {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int x: arr) {
        root = insertNode(root, x);
    }
    cout<<"Result: "<<searchNode(root, 14); // will give sorted list
}
