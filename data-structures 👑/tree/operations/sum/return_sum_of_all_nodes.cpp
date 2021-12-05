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
 * LOGIC: Return 0 for null and data on leaf node
 * Rest keep adding and returning them
 * 
 */ 
int returnNodeSum(Node* node){
    if(node==NULL) {
        return 0;
    }
    if(node->left==NULL && node->right==NULL) {
        return node->data;
    }
    int leftSum = returnNodeSum(node->left);
    int rightSum = returnNodeSum(node->right);
    return leftSum+rightSum;

    // return returnNodeSum(node->left) + returnNodeSum(node->right);
}


int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    cout<<returnNodeSum(root);
}
