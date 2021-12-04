#include <iostream>

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

int ind=-1;
Node* createTree(int arr[]) {
    ind++;
    if(arr[ind]==-1) {
        return NULL;
    }

    Node* newNode = new Node(arr[ind]);
    newNode->left = createTree(arr);
    newNode->right = createTree(arr);
    return newNode;
}

/**
 * LOGIC: Similar to return_sum_of_all_nodes
 * 1. Just keep returning the total sum
 * 2. And, assign left & right node sum to current node
 * 
 * 
 */ 
int descendentSum(Node* node){
    if(node==NULL) {
        return 0;
    }
    if(node->left==NULL && node->right==NULL) {
        return node->data;
    }
    int leftSum = descendentSum(node->left);
    int rightSum = descendentSum(node->right);
    int currNodeData  = node->data;
    node->data = leftSum+rightSum;
    return leftSum+rightSum+currNodeData;
    // return descendentSum(node->left) + descendentSum(node->right);
}

void traversePreOrder(Node* node) {

    if(node==NULL) {
        cout<<"-1"<<" ";
        return;
    }
    cout<<node->data<<" ";
    traversePreOrder(node->left);
    traversePreOrder(node->right);
}


int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    descendentSum(root);
    traversePreOrder(root);
}
