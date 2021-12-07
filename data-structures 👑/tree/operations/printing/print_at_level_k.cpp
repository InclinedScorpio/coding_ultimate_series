#include <iostream>

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

void printAtLevelK(Node* node, int k, int level=0) {
    if(node==NULL) {
        return;
    }
    if(level==k){ 
        cout<<node->data<<" ";
        return;
    }
    printAtLevelK(node->left, k, level+1);
    printAtLevelK(node->right, k, level+1);
}



int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    printAtLevelK(root, 2);
}