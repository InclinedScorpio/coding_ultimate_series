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

void preOrderTraversal(Node* node) {
    if(node==NULL) {
        return;
    } 

    cout<<node->data<<" ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

queue<Node*> storeData;

// level order traversal
void bfsTraversal(Node* node) {
    if(!node) {
        return;
    }
    if(storeData.empty()) {
        storeData.push(node);
    }
    if(node->left) {
        storeData.push(node->left);
    }
    if(node->right) {
        storeData.push(node->right);
    }
    cout<<storeData.front()->data<<" ";
    storeData.pop();

    bfsTraversal(storeData.front());
}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);

    // preOrderTraversal(root);

    bfsTraversal(root);
}