#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
    }
};

int globalIndex=-1;

Node* createTree(int *arr) {
    globalIndex++;
    if(arr[globalIndex]<0) {
        return NULL;
    }
    Node* node = new Node(arr[globalIndex]);
    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}

/**
 * Logic: Think about the terminating condition
 * & how we can send value to every next node
 * Returning the value and checking the max among
 * both sides everytime.
 * 
 */ 
int findMaxHeight(Node* tree, int addMeNode) {
    if(tree==NULL) {
        return addMeNode-1;
    }
    int left, right;
    left = findMaxHeight(tree->left, addMeNode+1);
    right = findMaxHeight(tree->right, addMeNode+1);
    return max(left, right);
}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    cout<<findMaxHeight(root, 0);
}